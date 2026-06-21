#define CDDA_TRACE
#include "common/common.h"
#include "event/event.h"
#include "time/time.h"
#include "aud_ops.h"

#include <string.h>
#include <go32.h>
#include <dpmi.h>

#define LINEAR_BUFFER_OFF(x) ((x) & 0xf)
#define LINEAR_BUFFER_SEG(x) ((x) >> 4)

#define CD_DRIVE_STATUS_FLAG_ERROR (1 << 15)
#define CD_DRIVE_STATUS_FLAG_BUSY (1 << 9)
#define CD_DRIVE_STATUS_FLAG_DONE (1 << 8)

// Requires MSCDEX v2.10+

#pragma pack(push, 1)

// length = 13
typedef struct RequestHeader
{
	u8 length;      // 00
	u8 subunitCode; // 01
	u8 commandCode; // 02
	u16 status;     // 03
	u8 reserved[8];
} RequestHeader;

/* command code = 3 */
typedef struct IoctlInputReq
{
	RequestHeader requestHeader;
	u8 mediaDescriptor; // 0D

	u16 transferAddressOff; // 0E
	u16 transferAddressSeg; // 10
} IoctlInputReq;

// ioctl code = 10, transfer length = 7
typedef struct AudioDiskInfo
{
	u8 controlBlockCode; // == 10
	u8 lowestTrackNumber;
	u8 highestTrackNumber;
	u32 leadoutPosition;
} AudioDiskInfo;

// ioctl code = 11, transfer length = 7
typedef struct AudioTrackInfo
{
	u8 controlBlockCode; // == 11
	u8 trackNumber;
	u32 startingPoint;
	u8 trackControlInfo;
} AudioTrackInfo;

typedef struct PlayAudioReq
{
	RequestHeader requestHeader;
	u8 addressingMode;  // 0D
	u32 startingSector; // 0E
	u32 sectorsToRead;  // 12
} PlayAudioReq;

typedef struct StopAudioReq
{
	RequestHeader requestHeader;
} StopAudioReq;

#pragma pack(pop)

static bool s_cdromAvailable;
static u16 s_numberOfDriveLetters;
static u16 s_startingDriveLetter;

// trackLengthInSecond = hsg / 75
static u8 s_currentPlayingTrack;
static u8 s_queuedTrack;
static bool s_loopTrack;
static u32 s_playStartTimeMs;
static u32 s_lastPollTimeMs;
static u32 s_playingTrackLengthHsg;

static AudioDiskInfo s_audioDiskInfo;

static u32 RedbookToHsg(u32 redBook)
{
	u16 minutes = redBook >> 16;
	u8 seconds = redBook >> 8;
	u8 frames = redBook;

	return (u32)(minutes * 60 + seconds) * 75 + frames;
}

bool CdCheckMscdex(void)
{
	// INT 2Fh, AX = 1500h, BX = 0000h
	// CD-ROM - INSTALLATION CHECK
	__dpmi_regs r;
    r.x.ax = 0x1500;
	r.x.bx = 0;
    __dpmi_int(0x2f, &r);

	// BX = number of CD-ROM drive letters used
	// CX = starting drive letter(0 = A:)
	s_numberOfDriveLetters = r.x.bx;
	s_startingDriveLetter = r.x.cx;

	s_cdromAvailable = r.x.bx != 0;
	return s_cdromAvailable;
}

void CdSendDriverRequest(void* ptr, int size)
{
    // INT 2Fh, AX=1510h - send device driver request
	__dpmi_regs r;
	r.x.ax = 0x1510;

    // CX = CD-ROM drive letter
	r.x.cx = s_startingDriveLetter;

	// ES:BX: CD-ROM device driver request header
	dosmemput(ptr, size, __tb);

	r.x.es = LINEAR_BUFFER_SEG(__tb);
	r.x.bx = LINEAR_BUFFER_OFF(__tb);

	__dpmi_int(0x2f, &r);

	dosmemget(__tb, size, ptr);
}

u16 CdGetTimeMinuteSecond(void)
{
	// INT 21, 2C - get time
	// on return: DH = seconds(0 - 59)
	// CL = minutes(0 - 59)
	__dpmi_regs r;
	r.h.ah = 0x2c;
	__dpmi_int(0x21, &r);

	u16 bx = r.h.dh;
	u16 ax = r.h.cl;
	ax *= 60;
	ax += bx;
	return ax;
}

void CdRequestAudioDiskInfo(void)
{
	IoctlInputReq ioctlRead;

	if (!s_cdromAvailable)
		return;

#ifdef CDDA_TRACE
	debug("CdromAvailable %u", s_cdromAvailable);
	debug("NumberOfDriveLetters %u", s_numberOfDriveLetters);
	debug("StartingDriveLetter %u", s_startingDriveLetter);
#endif

	memset(&ioctlRead, 0, sizeof(ioctlRead));
	memset(&s_audioDiskInfo, 0, sizeof(s_audioDiskInfo));

	s_audioDiskInfo.controlBlockCode = 10;

	u32 audioDiskInfoLinearAddress = __tb + 0x400;
	dosmemput(&s_audioDiskInfo, sizeof(s_audioDiskInfo), audioDiskInfoLinearAddress);

	ioctlRead.requestHeader.commandCode = 3;
	ioctlRead.requestHeader.length = 18; /* FIXME: dosbox doesn't seem to care */

	ioctlRead.transferAddressOff = LINEAR_BUFFER_OFF(audioDiskInfoLinearAddress);
	ioctlRead.transferAddressSeg = LINEAR_BUFFER_SEG(audioDiskInfoLinearAddress);

#ifdef CDDA_TRACE
	debug("_tb = %d:%d", LINEAR_BUFFER_SEG(__tb), LINEAR_BUFFER_OFF(__tb));
	debug("ioctl ES:BX = %d:%d", ioctlRead.transferAddressSeg, ioctlRead.transferAddressOff);
#endif

	CdSendDriverRequest(&ioctlRead, sizeof(ioctlRead));

#ifdef CDDA_TRACE
	debug("after ioctl len = %d", ioctlRead.requestHeader.length);
	debug("after ioctl ES:BX = %u:%u", ioctlRead.transferAddressSeg, ioctlRead.transferAddressOff);
#endif

	if (ioctlRead.requestHeader.status & CD_DRIVE_STATUS_FLAG_ERROR)
	{
		/* error */
	}

    dosmemget(audioDiskInfoLinearAddress, sizeof(s_audioDiskInfo), &s_audioDiskInfo);

#ifdef CDDA_TRACE
	debug("Status %x", ioctlRead.requestHeader.status);

	debug("Cbc %u", s_audioDiskInfo.controlBlockCode);
	debug("Low %u", s_audioDiskInfo.lowestTrackNumber);
	debug("High %u", s_audioDiskInfo.highestTrackNumber);
	debug("Leadout %lu", s_audioDiskInfo.leadoutPosition);
#endif
}

void CdPlayAudio(u8 track)
{
	AudioTrackInfo trackInfo;
	IoctlInputReq ioctlRead;
	PlayAudioReq playAudio;

	u32 startingSector;
	u32 stopSector;
	u32 sectorsToRead;

	if (!s_cdromAvailable)
		return;

#ifdef CDDA_TRACE
	debug("CDDA: PLAY %d", track);
#endif

	s_currentPlayingTrack = 0;
	s_loopTrack = false;

	memset(&ioctlRead, 0, sizeof(ioctlRead));
	memset(&trackInfo, 0, sizeof(trackInfo));

	trackInfo.controlBlockCode = 11;
	trackInfo.trackNumber = track;

	u32 trackInfoLinearAddress = __tb + 0x400;
	dosmemput(&trackInfo, sizeof(trackInfo), trackInfoLinearAddress);

	ioctlRead.requestHeader.commandCode = 3;
	ioctlRead.requestHeader.length = 18; // FIXME: dosbox doesn't seem to care

	ioctlRead.transferAddressOff = LINEAR_BUFFER_OFF(trackInfoLinearAddress);
	ioctlRead.transferAddressSeg = LINEAR_BUFFER_SEG(trackInfoLinearAddress);

	CdSendDriverRequest(&ioctlRead, sizeof(ioctlRead));

	if (ioctlRead.requestHeader.status & CD_DRIVE_STATUS_FLAG_ERROR)
	{
		/* error */
#ifdef CDDA_TRACE
		debug("CDDA: ERROR status & CD_DRIVE_STATUS_FLAG_ERROR");
#endif
		return;
	}

	dosmemget(trackInfoLinearAddress, sizeof(trackInfo), &trackInfo);

	if (trackInfo.trackControlInfo & 0x40)
	{
		/* data track */
#ifdef CDDA_TRACE
		debug("CDDA: ERROR trackControlInfo & 0x40");
#endif
		return;
	}

	startingSector = trackInfo.startingPoint;

	if (track == s_audioDiskInfo.highestTrackNumber)
	{
		stopSector = s_audioDiskInfo.leadoutPosition;
	}
	else
	{
		trackInfo.trackNumber = track + 1;

		dosmemput(&trackInfo, sizeof(trackInfo), trackInfoLinearAddress);
		CdSendDriverRequest(&ioctlRead, sizeof(ioctlRead));
		dosmemget(trackInfoLinearAddress, sizeof(trackInfo), &trackInfo);

		stopSector = trackInfo.startingPoint;
	}

	sectorsToRead = RedbookToHsg(stopSector) - RedbookToHsg(startingSector);

	s_playingTrackLengthHsg = sectorsToRead;

	memset(&playAudio, 0, sizeof(playAudio));

	playAudio.requestHeader.commandCode = 132;
	playAudio.requestHeader.length = 21;

	// just use hsg mode?
	playAudio.addressingMode = 1;
	playAudio.startingSector = startingSector;
	playAudio.sectorsToRead = sectorsToRead;

	CdSendDriverRequest(&playAudio, sizeof(playAudio));

	s_currentPlayingTrack = track;

	// return playAudio.requestHeader.status;
}

void CdStopAudio(void)
{
	StopAudioReq stopAudio;

	if (!s_cdromAvailable)
		return;

#ifdef CDDA_TRACE
	debug("CDDA: STOP");
#endif

	s_currentPlayingTrack = 0;
	s_loopTrack = false;

	stopAudio.requestHeader.commandCode = 133;
	stopAudio.requestHeader.length = 5;

	CdSendDriverRequest(&stopAudio, sizeof(stopAudio));

	// return stopAudio.requestHeader.status;
}

void CdPlayLoopAudio(u8 track)
{
#ifdef CDDA_TRACE
	debug("CDDA: LOOPING %d", track);
#endif

	if (s_currentPlayingTrack != 0 && track != s_currentPlayingTrack)
		CdStopAudio();

	CdPlayAudio(track);
	s_loopTrack = true;
	s_playStartTimeMs = TIME_GetTicksMs();
}

void CdOnStopped(void);

// required poll interval: 1 sec
void CdCallback(void)
{
	u32 currentMs;
	u32 trackLengthInMs;

	if (!s_cdromAvailable)
		return;

	if (s_currentPlayingTrack != 0)
	{
		currentMs = TIME_GetTicksMs();
		if (currentMs > s_lastPollTimeMs + 1000)
		{
			s_lastPollTimeMs = currentMs;

			trackLengthInMs = s_playingTrackLengthHsg * 1000 / 75;

			if (currentMs - s_playStartTimeMs >= trackLengthInMs)
			{
				int track = s_currentPlayingTrack;
				bool looping = s_loopTrack;
				CdStopAudio();
				if (looping)
				{
					CdPlayLoopAudio(track);
				}
				else
				{
					CdOnStopped();
				}
			}
		}
	}
}

void CdOnStopped(void)
{
	int queuedTrack = s_queuedTrack;

	s_queuedTrack = 0;
	s_currentPlayingTrack = 0;

	if (queuedTrack == 0)
	{
		return;
	}

	CdPlayLoopAudio(queuedTrack);
}

// Audio Driver

static void AUDIO_CDDA_Init(void)
{
	CdCheckMscdex();

	if (s_cdromAvailable)
	{
		CdRequestAudioDiskInfo();
		EVT_RegisterCallback(CdCallback);
	}
}

static void AUDIO_CDDA_Cleanup(void)
{
	CdStopAudio();
}

static void AUDIO_CDDA_PlayBgm(int id)
{
	s_queuedTrack = 0;

	if (s_currentPlayingTrack == id)
	{
		s_loopTrack = true;
		return;
	}

	CdPlayLoopAudio(id);
}

static void AUDIO_CDDA_QueueBgm(int id)
{
	if (s_currentPlayingTrack == 0)
	{
		s_queuedTrack = 0;
		CdPlayAudio(id);
		return;
	}

	s_queuedTrack = id;
	s_loopTrack = false;
}

static void AUDIO_CDDA_StopBgm(void)
{
	CdStopAudio();
}

static AudioMusicDriverOps s_musicOps =
{
	.Initialize = AUDIO_CDDA_Init,
	.Cleanup = AUDIO_CDDA_Cleanup,
	.PlayBgm = AUDIO_CDDA_PlayBgm,
	.QueueBgm = AUDIO_CDDA_QueueBgm,
	.StopBgm = AUDIO_CDDA_StopBgm
};

AudioMusicDriverOps* AUDIO_CDDA_GetMusicOps(void)
{
	return &s_musicOps;
}
