#undef NDEBUG
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <SDL3/SDL.h>
#include "common/save_slots.h"
#include "common/file.h"
#include "mod/package.h"
#include "mod/runtime.h"
#include "mod/world_resources.h"
#include "graphics/widescreen.h"
#include "outsubs.h"
#include "graphics/grap_sdl.h"
#include "graphics/grap_buf.h"
#include "graphics/grap.h"
#include "funcs.h"
#include "savegame.h"
#include "npc.h"
#include "talk.h"
#include "vars.h"
#include "key/key.h"
#include "event/event.h"
void GRAP_SDL_Initialize(void);
void GRAP_SDL_Cleanup(void);
static void writeResourcePackage(const char *path, const char *name,
                                 const byte *base, const byte *changed, size_t size) {
    FILE *f = fopen(path, "wb");assert(f);
    assert(fwrite("IMOD0001",1,8,f)==8);
    assert(FILE_WriteU32LE(f,4) && FILE_WriteU32LE(f,1));
    assert(fwrite("Test",1,4,f)==4);
    size_t length=strlen(name);assert(FILE_WriteU32LE(f,(u32)length));
    assert(fwrite(name,1,length,f)==length);
    assert(FILE_WriteU32LE(f,(u32)size) && FILE_WriteU32LE(f,(u32)size));
    assert(FILE_WriteU32LE(f,MOD_Crc32(base,size)) && FILE_WriteU32LE(f,MOD_Crc32(changed,size)));
    assert(FILE_WriteU32LE(f,1) && FILE_WriteU32LE(f,0) && FILE_WriteU32LE(f,(u32)size));
    assert(fwrite(changed,1,size,f)==size);assert(!fclose(f));
}
static void engineWorldIndex(void) {
    assert(SDL_SetEnvironmentVariable(SDL_GetEnvironment(), "U5D_MODS_DIR", "world-game/Mods", true));
    assert(SDL_CreateDirectory("world-game/Mods"));
    byte original[U5_WORLD_INDEX_OFFSET+256]={0}, changed[sizeof(original)];
    memcpy(original+U5_WORLD_INDEX_OFFSET,U5_BritanniaDefaultIndex,256);
    memcpy(changed,original,sizeof(original));
    memset(changed+U5_WORLD_INDEX_OFFSET,255,256);
    changed[U5_WORLD_INDEX_OFFSET]=1;changed[U5_WORLD_INDEX_OFFSET+255]=0;
    FILE *f=fopen("world-game/DATA.OVL","wb");assert(f);
    assert(fwrite(original,1,sizeof(original),f)==sizeof(original));assert(!fclose(f));
    f=fopen("world-game/BRIT.DAT","wb");assert(f);
    for(int i=0;i<65536;++i) assert(fputc(i>=256 && i<512?7:5,f)!=EOF);
    assert(!fclose(f));writeResourcePackage("world-game/Mods/index.imperamod","DATA.OVL",original,changed,sizeof(original));
    const char *exported=getenv("IMPERA_WORLD_TEST_PACKAGE");
    if(exported) {
        FILE *input=fopen(exported,"rb"),*output=fopen("world-game/Mods/index.imperamod","wb");
        assert(input && output);byte buffer[4096];size_t n;
        while((n=fread(buffer,1,sizeof(buffer),input))) assert(fwrite(buffer,1,n,output)==n);
        assert(!ferror(input));assert(!fclose(input));assert(!fclose(output));
    }
    FILE_SetDataDirectory("world-game");assert(MOD_LoadedCount()==1);
    D_5893_map_id=0;D_5895_map_level=0;D_589b=0;D_589c=0;
    OUTSUBS_01b4(-1,-1);
    for(int i=0;i<768;++i) assert(D_6608[i]==(i<256?7:1));
    /* Expanded viewport reads the same index outside the resident map. */
    D_5896_map_x=240;D_5897_map_y=240;assert(WIDE_MapTile(0,0)==5);
    changed[U5_WORLD_INDEX_OFFSET+255]=1;
    writeResourcePackage("world-game/Mods/index.imperamod","DATA.OVL",original,changed,sizeof(original));FILE_SetDataDirectory("world-game");
    assert(WIDE_MapTile(0,0)==7); /* remount invalidates extended block cache */
    remove("world-game/Mods/index.imperamod");remove("world-game/DATA.OVL");
    FILE_SetDataDirectory("world-game");assert(MOD_LoadedCount()==0);
    OUTSUBS_01b4(-1,-1);
    for(int i=0;i<512;++i) assert(D_6608[i]==1); /* original water chunks restored */
    assert(WIDE_MapTile(0,0)==5);
    FILE_SetDataDirectory(NULL);remove("world-game/BRIT.DAT");
    SDL_RemovePath("world-game/Mods");SDL_RemovePath("world-game");
    assert(SDL_UnsetEnvironmentVariable(SDL_GetEnvironment(), "U5D_MODS_DIR"));
}
static void writeWorld(const char* file,byte value,int bytes)
{
    FILE* f=FILE_Open(file,"wb");assert(f);
    for(int i=0;i<bytes;i++) assert(fputc(value,f)!=EOF);
    assert(!fclose(f));
}
static SDL_EnumerationResult cleanup(void* unused,const char* directory,const char* name)
{
    (void)unused;char dir[512],file[512];
    SDL_snprintf(dir,sizeof(dir),"%s/%s",directory,name);
    const char* parts[]={"SAVED.GAM","SAVED.OOL","meta.txt","thumbnail.bmp"};
    for(int i=0;i<4;i++) { SDL_snprintf(file,sizeof(file),"%s/%s",dir,parts[i]);SDL_RemovePath(file); }
    SDL_RemovePath(dir);return SDL_ENUM_CONTINUE;
}
static char initialIds[4][41];static int initialCount;
static SDL_EnumerationResult initialSlots(void* unused,const char* dir,const char* id)
{
    (void)unused;
    if(id[0]=='.') return SDL_ENUM_CONTINUE;
    char file[512],name[40];SDL_snprintf(file,sizeof(file),"%s/%s/meta.txt",dir,id);
    FILE* f=FILE_Open(file,"r");assert(f);assert(fgets(name,sizeof(name),f));
    unsigned long long ms;assert(fscanf(f,"%llu",&ms)==1);
    unsigned int map,level,x,y;assert(fscanf(f," location %u %u %u %u",&map,&level,&x,&y)==4);
    assert((map==13 || map==2) && level==0);fclose(f);
    assert(!strcmp(name,"New Hero\n") && ms==0);
    assert(initialCount<4);SDL_strlcpy(initialIds[initialCount++],id,41);
    return SDL_ENUM_CONTINUE;
}
static int step;
static bool reloadCalled;
static void reload(void) { reloadCalled=true; }
static Uint32 cancel(void* unused,SDL_TimerID id,Uint32 interval)
{
    (void)unused;(void)id;(void)interval;
    SDL_Event e={0};e.type=SDL_EVENT_KEY_DOWN;e.key.key=SDLK_ESCAPE;
    assert(SDL_PushEvent(&e));return 0;
}
static Uint32 accept(void* unused,SDL_TimerID id,Uint32 interval)
{
    (void)unused;(void)id;(void)interval;
    SDL_Event e={0};e.type=SDL_EVENT_KEY_DOWN;e.key.key=SDLK_RETURN;
    assert(SDL_PushEvent(&e));return 0;
}
static int deleteStep;
static bool deleteConfirm;
static Uint32 deleteInput(void* unused,SDL_TimerID id,Uint32 interval)
{
    (void)unused;(void)id;(void)interval;
    SDL_Keycode keys[]={SDLK_DOWN,SDLK_DELETE,deleteConfirm?SDLK_Y:SDLK_N,SDLK_ESCAPE};
    SDL_Event e={0};e.type=SDL_EVENT_KEY_DOWN;e.key.key=keys[deleteStep++];
    assert(SDL_PushEvent(&e));return deleteStep==4?0:50;
}
static bool captureBrowser;
static int expectedLocation=-1;
static bool checkDrag, sawDrag;
static bool checkNoLegacy, sawNoLegacy;
bool __real_SDL_RenderPresent(SDL_Renderer* renderer);
bool __wrap_SDL_RenderPresent(SDL_Renderer* renderer)
{
    bool presented=__real_SDL_RenderPresent(renderer);
    if(expectedLocation>=0) {
        for(int y=0;y<8;y++) for(int x=0;x<8;x++)
            assert(g_linearEgaBuffer0[(49+y)*320+20+x]==((D_539c[0][expectedLocation*8+y]&(0x80>>x))?0:15));
        expectedLocation=-1;
    }
    if(checkDrag && g_linearEgaBuffer0[173*320+300]==15) {
        assert(g_linearEgaBuffer0[56*320+300]==7);
        sawDrag=true;
    }
    if(checkNoLegacy) {
        /* First named slot occupies the former legacy row and is selected. */
        assert(g_linearEgaBuffer0[39*320+16]==15);
        assert(g_linearEgaBuffer0[66*320+16]==15);
        assert(g_linearEgaBuffer0[67*320+16]==0);
        sawNoLegacy=true;checkNoLegacy=false;
    }
    if(captureBrowser && D_539c[0]) {
        bool title=true;
        for(int y=0;y<8;y++) for(int x=0;x<8;x++)
            if(g_linearEgaBuffer0[(12+y)*320+124+x]!=((D_539c[0]['S'*8+y]&(0x80>>x))?15:0)) title=false;
        if(title) {
            SDL_Surface* image=SDL_RenderReadPixels(renderer,NULL);assert(image);
            Uint8 r,g,b,a;
            assert(SDL_ReadSurfacePixel(image,270*4,80+70*4,&r,&g,&b,&a));
            assert(r==255 && g==0 && b==0); /* Thumbnail overlay, not EGA menu pixels. */
            assert(SDL_SaveBMP(image,"browser.bmp"));SDL_DestroySurface(image);
            captureBrowser=false;
        }
    }
    return presented;
}
static Uint32 input(void* unused,SDL_TimerID id,Uint32 interval)
{
    (void)unused;(void)id;(void)interval;
    SDL_Event e={0};e.type=SDL_EVENT_KEY_DOWN;e.key.key=SDLK_RETURN;
    if(step==1) { e.type=SDL_EVENT_TEXT_INPUT;e.text.text="Browser Save"; }
    if(step==3) return 0;
    assert(SDL_PushEvent(&e));step++;return 100;
}
int main(void)
{
    assert(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO));GRAP_Initialize();ULTIMA_1158_InitTimer();
    engineWorldIndex();
    assert(SDL_CreateDirectory("SAVEGAME"));
    SDL_EnumerateDirectory("SAVEGAME/slots",cleanup,NULL);
    writeWorld("SAVEGAME/BRIT.OOL",0x12,256);
    writeWorld("SAVEGAME/UNDER.OOL",0x34,256);
    writeWorld("SAVEGAME/SAVED.OOL",0x56,512);
    /* Enhanced Look's optional knowledge section must be accepted by both
     * the browser preflight and the actual save reader. */
    unsigned char knowledge[17] = "IKNOW001";
    knowledge[8] = knowledge[16] = 1;
    unsigned crc = MOD_Crc32(knowledge + 16, 1);
    for (int i=0;i<4;i++) knowledge[12+i] = crc >> (i*8);
    FILE *known = tmpfile();assert(known);
    assert(fwrite(knowledge,1,sizeof(knowledge),known)==sizeof(knowledge));
    rewind(known);assert(TALK_ReadKnowledge(known,1));fclose(known);
    D_57a8=123;assert(FILE_WriteSavegameFile("SAVED.GAM")==0);
    SDL_Surface* preview=SDL_CreateSurface(160,100,SDL_PIXELFORMAT_ARGB8888);assert(preview);
    assert(SDL_FillSurfaceRect(preview,NULL,SDL_MapSurfaceRGB(preview,255,0,0)));
    assert(SDL_SaveBMP(preview,"preview.bmp"));SDL_DestroySurface(preview);
    SLOTS_ResetTime();SLOTS_StartTime();SDL_Delay(25);
    assert(SLOTS_Write("1","First Save",NULL));
    uint64_t first=SLOTS_PlayMilliseconds();assert(first>=25);
    D_57a8=456;SDL_Delay(25);assert(SLOTS_Write("2","Second Save",NULL));
    for(int i=3;i<90;i++) {
        char id[40];SDL_snprintf(id,sizeof(id),"%d",i);
        assert(SLOTS_Write(id,"Same name is allowed","preview.bmp"));
    }
    assert(!SLOTS_Write("../escape","Bad",NULL));
    assert(!SLOTS_Write("1","Bad\nName",NULL));
    assert(SLOTS_Load("1"));assert(FILE_ReadSavegameFile("SAVED.GAM")==0);assert(D_57a8==123);
    known=tmpfile();assert(known && TALK_WriteKnowledge(known));
    assert(ftell(known)==sizeof(knowledge));rewind(known);
    unsigned char restored[17];assert(fread(restored,1,sizeof(restored),known)==sizeof(restored));
    assert(!memcmp(restored,knowledge,sizeof(knowledge)));fclose(known);
    assert(SLOTS_Write("9997","Knowledge checksum",NULL));
    known=FILE_Open("SAVEGAME/slots/9997/SAVED.GAM","r+b");assert(known);
    assert(!fseek(known,-1,SEEK_END));int last=fgetc(known);assert(last!=EOF);
    assert(!fseek(known,-1,SEEK_END) && fputc(last^1,known)!=EOF);fclose(known);
    D_57a8=321;assert(!SLOTS_Load("9997") && D_57a8==321);
    assert(SLOTS_Delete("9997"));D_57a8=123;
    FILE* f=FILE_Open("SAVEGAME/SAVED.OOL","rb");assert(f);
    for(int i=0;i<512;i++) assert(fgetc(f)==(i<256?0x12:0x34));fclose(f);
    SLOTS_StartTime();assert(SLOTS_PlayMilliseconds()>=25 && SLOTS_PlayMilliseconds()<first+100);
    D_57a8=789;
    assert(SDL_RenamePath("SAVEGAME/BRIT.OOL","SAVEGAME/BRIT.backup"));
    assert(!SLOTS_Write("1","Failed overwrite",NULL));
    assert(SDL_RenamePath("SAVEGAME/BRIT.backup","SAVEGAME/BRIT.OOL"));
    assert(SLOTS_Load("1"));assert(FILE_ReadSavegameFile("SAVED.GAM")==0);assert(D_57a8==123);
    writeWorld("SAVEGAME/slots/2/SAVED.OOL",0,3);
    assert(!SLOTS_Load("2"));assert(FILE_ReadSavegameFile("SAVED.GAM")==0);assert(D_57a8==123);
    byte font[1024];f=FILE_Open("IBM.CH","rb");assert(f);
    assert(fread(font,1,1024,f)==1024);fclose(f);D_539c[0]=font;
    D_5893_map_id=0x40;D_58a4=0;memset(g_linearEgaBuffer0,3,320*200);
    GRAP_BUF_MarkDirty();GRAP_BUF_Present();
    /* A stale menu render must never become the next gameplay capture. */
    GRAP_SDL_SetPixelUI(true);memset(g_linearEgaBuffer0,15,320*200);
    GRAP_BUF_Present();GRAP_SDL_SetPixelUI(false);
    memset(g_linearEgaBuffer0,3,320*200);
    SDL_Surface* gameplay=GRAP_SDL_CaptureFrame();assert(gameplay);
    Uint8 r,g,b,a;
    assert(SDL_ReadSurfacePixel(gameplay,gameplay->w/2,gameplay->h/2,&r,&g,&b,&a));
    assert(r==0 && g==170 && b==170);SDL_DestroySurface(gameplay);
    captureBrowser=true;
    assert(SDL_AddTimer(100,input,NULL));
    assert(SLOTS_ShowSave());
    for(int i=0;i<320*200;i++) assert(g_linearEgaBuffer0[i]==3);
    assert(step==3 && !captureBrowser);
    /* Legacy stays hidden by default even with valid working files. */
    checkNoLegacy=true;sawNoLegacy=false;
    assert(SDL_AddTimer(50,cancel,NULL));assert(!SLOTS_ShowLoad());assert(sawNoLegacy);
    SLOTS_SetLegacyEnabled(true);
    /* Wheel scrolling and dragging the scrollbar must also allow mouse return. */
    SDL_Event event={0};event.type=SDL_EVENT_MOUSE_WHEEL;event.wheel.y=0;
    assert(SDL_PushEvent(&event));
    event.type=SDL_EVENT_MOUSE_BUTTON_DOWN;event.button.button=SDL_BUTTON_LEFT;
    event.button.x=302*4;event.button.y=80+58*4;assert(SDL_PushEvent(&event));
    event.type=SDL_EVENT_MOUSE_MOTION;event.motion.x=290*4;event.motion.y=80+210*4;assert(SDL_PushEvent(&event));
    event.type=SDL_EVENT_MOUSE_BUTTON_UP;assert(SDL_PushEvent(&event));
    event.type=SDL_EVENT_MOUSE_BUTTON_DOWN;event.button.button=SDL_BUTTON_LEFT;
    event.button.x=24*4;event.button.y=80+184*4;assert(SDL_PushEvent(&event));
    checkDrag=true;
    assert(!SLOTS_ShowLoad());assert(sawDrag);checkDrag=false;
    for(int i=0;i<320*200;i++) assert(g_linearEgaBuffer0[i]==3);
    /* Missing legacy files hide its row while named slots remain usable. */
    assert(SDL_RenamePath("SAVEGAME/SAVED.GAM","SAVEGAME/SAVED.GAM.test-backup"));
    checkNoLegacy=true;
    assert(SDL_AddTimer(50,cancel,NULL));assert(!SLOTS_ShowLoad());assert(sawNoLegacy);
    assert(SDL_AddTimer(50,accept,NULL));assert(SLOTS_ShowLoad());
    assert(SDL_RemovePath("SAVEGAME/SAVED.GAM.test-backup"));
    /* Shortcuts are inert outside gameplay, including title/cutscene mode. */
    SDL_Event shortcut={0};shortcut.type=SDL_EVENT_KEY_DOWN;shortcut.key.mod=SDL_KMOD_CTRL;
    KEY_SDL_SetGameplayInput(0);
    shortcut.key.key=SDLK_W;assert(SDL_PushEvent(&shortcut));assert(KEY_PollKey()==0x1a);
    shortcut.key.key=SDLK_L;assert(SDL_PushEvent(&shortcut));assert(KEY_PollKey()==0x1a);
    KEY_SDL_SetGameplayInput(1);EVT_SetImmediateExit(1);
    assert(SDL_PushEvent(&shortcut));assert(KEY_PollKey()==0x1a);
    EVT_SetImmediateExit(0);
    /* Both gameplay shortcuts open a browser; cancellation does not reload. */
    SLOTS_SetReloadCallback(reload);
    shortcut.key.key=SDLK_W;assert(SDL_PushEvent(&shortcut));
    assert(SDL_AddTimer(50,cancel,NULL));assert(KEY_PollKey()==0);assert(!reloadCalled);
    shortcut.key.key=SDLK_L;assert(SDL_PushEvent(&shortcut));
    assert(SDL_AddTimer(50,cancel,NULL));assert(KEY_PollKey()==0);assert(!reloadCalled);
    /* Selecting a load invokes the top-level restart hook. */
    assert(SDL_PushEvent(&shortcut));assert(SDL_AddTimer(50,accept,NULL));
    assert(KEY_PollKey()==0);assert(reloadCalled);
    SLOTS_SetReloadCallback(NULL);KEY_SDL_SetGameplayInput(0);
    /* Legacy directory spelling remains supported. */
    assert(SDL_RenamePath("SAVEGAME","savegame"));
    assert(SLOTS_Write("900","Lowercase directory",NULL));
    assert(SLOTS_Load("900"));
    assert(SDL_RenamePath("savegame","SAVEGAME"));
    /* A reload abandons the cursor poll while character advancement is disabled. */
    assert(SLOTS_Load("1"));D_538e=0;
    SLOTS_ReloadActiveGame();
    assert(D_538e==1 && D_57a8==123);
    assert(D_535e_textWindows[1].left==24 && D_535e_textWindows[1].right==39);
    SLOTS_ResetTime();SLOTS_StartTime();assert(SLOTS_PlayMilliseconds()<10);
    assert(!SLOTS_Delete("../1"));
    deleteStep=0;deleteConfirm=false;
    assert(SDL_AddTimer(50,deleteInput,NULL));assert(!SLOTS_ShowLoad());
    assert(SLOTS_Load("900"));
    deleteStep=0;deleteConfirm=true;
    assert(SDL_AddTimer(50,deleteInput,NULL));assert(!SLOTS_ShowLoad());
    assert(!SLOTS_Load("900"));
    assert(!SLOTS_Delete("900"));
    /* New-character state becomes an ordinary named slot, with fresh worlds. */
    char location[64];
    SLOTS_LocationName(2,0,location,sizeof(location));assert(!strcmp(location,"Britain"));
    SLOTS_LocationName(0,0,location,sizeof(location));assert(!strcmp(location,"Britannia"));
    SLOTS_LocationName(0,255,location,sizeof(location));assert(!strcmp(location,"Underworld"));
    SLOTS_LocationName(33,3,location,sizeof(location));assert(!strcmp(location,"Dungeon Deceit"));
    SLOTS_LocationName(17,0,location,sizeof(location));assert(!strcmp(location,"Lord British's Castle"));
    SLOTS_LocationName(255,0,location,sizeof(location));assert(!strcmp(location,"Unknown Location"));
    SDL_EnumerateDirectory("SAVEGAME/slots",cleanup,NULL);
    strcpy(D_55a8_party[0].name,"New Hero");D_57a8=678;D_5893_map_id=13;D_5895_map_level=0;
    writeWorld("SAVEGAME/BRIT.OOL",0x12,256);writeWorld("SAVEGAME/UNDER.OOL",0x34,256);
    assert(SLOTS_Write("9999","Pre-mod save",NULL));
    assert(SDL_CreateDirectory("starting-game/Mods"));
    assert(SDL_SetEnvironmentVariable(SDL_GetEnvironment(), "U5D_MODS_DIR", "starting-game/Mods", true));
    byte objectBase[256],britObjects[256],underObjects[256];
    memset(objectBase,0xab,256);memset(britObjects,0x23,256);memset(underObjects,0x45,256);
    const char *objectFiles[]={"INIT.OOL","BRIT.OOL","UNDER.OOL"};
    for(int i=0;i<3;i++) {
        char objectPath[128];SDL_snprintf(objectPath,sizeof(objectPath),"starting-game/%s",objectFiles[i]);
        writeWorld(objectPath,0xab,256);
    }
    writeResourcePackage("starting-game/Mods/brit.imperamod","BRIT.OOL",objectBase,britObjects,256);
    writeResourcePackage("starting-game/Mods/under.imperamod","UNDER.OOL",objectBase,underObjects,256);
    byte npcBase[4608]={0}, npcChanged[4608];
    memcpy(npcChanged,npcBase,sizeof(npcChanged));
    int npcStart=4*576;
    for(int slot=5;slot<=8;slot++) {
        int record=npcStart+slot*16;
        for(int phase=0;phase<3;phase++) {
            npcChanged[record+3+phase]=(byte)(10+slot);
            npcChanged[record+6+phase]=(byte)(12+slot);
            npcChanged[record+9+phase]=(byte)(slot==7?1:0);
        }
        npcChanged[npcStart+512+slot]=(byte)(slot==6?128:80);
        npcChanged[npcStart+544+slot]=(byte)(slot==6?0:42);
    }
    f=fopen("starting-game/DWELLING.NPC","wb");assert(f);
    assert(fwrite(npcBase,1,sizeof(npcBase),f)==sizeof(npcBase));fclose(f);
    f=fopen("starting-game/TOWNE.NPC","wb");assert(f);
    assert(fwrite(npcBase,1,sizeof(npcBase),f)==sizeof(npcBase));fclose(f);
    writeResourcePackage("starting-game/Mods/npcs.imperamod","DWELLING.NPC",npcBase,npcChanged,sizeof(npcChanged));
    FILE_SetDataDirectory("starting-game");assert(MOD_LoadedCount()==3);
    assert(SLOTS_Load("9999"));
    f=FILE_Open("SAVEGAME/SAVED.OOL","rb");assert(f);
    for(int i=0;i<512;i++) assert(fgetc(f)==(i<256?0x12:0x34));fclose(f);
    assert(SLOTS_Delete("9999"));
    memset(D_b21e,0xee,512);
    D_5893_map_id=0;D_5895_map_level=0;memset(D_5c5a,0xee,256);
    assert(SLOTS_CreateInitial());assert(!memcmp(D_5c5a,britObjects,256));
    D_5895_map_level=255;
    assert(SLOTS_CreateInitial());assert(!memcmp(D_5c5a,underObjects,256));
    SDL_EnumerateDirectory("SAVEGAME/slots",cleanup,NULL);
    D_5893_map_id=13;D_5895_map_level=0;memset(D_5c5a,0x77,256);
    memset(D_b21e,0xee,512);
    writeWorld("SAVEGAME/BRIT.OOL",0x12,256);writeWorld("SAVEGAME/UNDER.OOL",0x34,256);
    memset(D_5b5a,0,sizeof(D_5b5a));D_5b5a[12*4+1]=1; /* NPC 8 was already removed. */
    D_587f=8;
    assert(SLOTS_CreateInitial());
    for(int i=0;i<8;i++) assert(((byte*)D_5c5a)[i]==0x77); /* Party actor remains intact. */
    assert(D_5893_map_id==13 && D_5895_map_level==0 && D_587f==8 && D_57a8==678);
    for(int slot=5;slot<=6;slot++) {
        int actor=D_5f5e[slot]._c;assert(actor>0 && actor<32);
        assert(D_5f5e[slot]._0 && D_5c5a[actor]._0_tile==(slot==5?80:128));
        assert(D_5c5a[actor]._2_x==10+slot && D_5c5a[actor]._3_y==12+slot);
        assert(D_5f5e[slot]._a==(slot==5?42:0));
    }
    assert(D_5f5e[7]._0 && !D_5f5e[7]._c); /* Another floor is not spawned here. */
    assert(!D_5f5e[8]._0 && !D_659e[8]);
    /* A bad/missing bank must fail before replacing any resident actors. */
    ActorFmt residents[32];memcpy(residents,D_5c5a,sizeof(residents));
    D_5893_map_id=17;assert(!NPC_InitializeNewGame());
    assert(!memcmp(residents,D_5c5a,sizeof(residents)));D_5893_map_id=13;
    f=FILE_Open("SAVEGAME/BRIT.OOL","rb");assert(f);assert(fgetc(f)==0x12);fclose(f);
    f=FILE_Open("SAVEGAME/UNDER.OOL","rb");assert(f);assert(fgetc(f)==0x34);fclose(f);
    remove("SAVEGAME/BRIT.OOL");remove("SAVEGAME/UNDER.OOL");
    D_57a8=789;D_5893_map_id=2;D_5896_map_x=15;D_5897_map_y=30;
    assert(SLOTS_CreateInitial());
    SDL_EnumerateDirectory("SAVEGAME/slots",initialSlots,NULL);assert(initialCount==2);
    /* Journey Onward's ordinary menu selects the newest game with legacy off. */
    SLOTS_SetLegacyEnabled(false);D_57a8=0;
    expectedLocation='B';
    assert(SDL_AddTimer(50,accept,NULL));assert(SLOTS_ShowLoad());assert(expectedLocation==-1);
    assert(FILE_ReadSavegameFile("SAVED.GAM")==0);assert(D_57a8==789);
    assert(!strcmp(D_55a8_party[0].name,"New Hero"));assert(D_5893_map_id==2);
    f=FILE_Open("SAVEGAME/SAVED.OOL","rb");assert(f);
    for(int i=0;i<512;i++) assert(fgetc(f)==(i<256?0x23:0x45));fclose(f);
    const char *hut=strcmp(initialIds[0],initialIds[1])>0?initialIds[1]:initialIds[0];
    assert(SLOTS_Load(hut));assert(FILE_ReadSavegameFile("SAVED.GAM")==0);
    assert(D_5893_map_id==13 && D_5f5e[5]._0 && D_5f5e[6]._0);
    assert(D_5c5a[D_5f5e[5]._c]._0_tile==80 && D_5c5a[D_5f5e[6]._c]._0_tile==128);
    FILE_SetDataDirectory(NULL);
    remove("starting-game/Mods/brit.imperamod");remove("starting-game/Mods/under.imperamod");
    for(int i=0;i<3;i++) {
        char objectPath[128];SDL_snprintf(objectPath,sizeof(objectPath),"starting-game/%s",objectFiles[i]);
        remove(objectPath);
    }
    remove("starting-game/Mods/npcs.imperamod");
    remove("starting-game/DWELLING.NPC");remove("starting-game/TOWNE.NPC");
    SDL_RemovePath("starting-game/Mods");SDL_RemovePath("starting-game");
    assert(SDL_UnsetEnvironmentVariable(SDL_GetEnvironment(), "U5D_MODS_DIR"));
    /* Older two-line metadata remains loadable. */
    const char* latest=strcmp(initialIds[0],initialIds[1])>0?initialIds[0]:initialIds[1];
    char meta[512];SDL_snprintf(meta,sizeof(meta),"SAVEGAME/slots/%s/meta.txt",latest);
    f=FILE_Open(meta,"w");assert(f);assert(fputs("Old Format\n123\n",f)>=0);fclose(f);
    assert(SLOTS_Load(latest));expectedLocation='U';
    assert(SDL_AddTimer(50,cancel,NULL));assert(!SLOTS_ShowLoad());assert(expectedLocation==-1);
    /* Named-slot validation must accept the extended NPC prefix as well. */
    writeWorld("SAVEGAME/BRIT.OOL", 0x12, 256);
    writeWorld("SAVEGAME/UNDER.OOL", 0x34, 256);
    D_imperaNpcCount = 33;
    D_5893_map_id = 13;
    memset(&D_5f5e[32], 0, sizeof(D_5f5e[32]));
    memset(&D_5c5a[32], 0, sizeof(D_5c5a[32]));
    memset(&D_5d5e[32], 0, sizeof(D_5d5e[32]));
    memset(&D_615e[32], 0, sizeof(D_615e[32]));
    D_655e[32] = -1;
    D_65c2[32] = 0;
    D_659e[32] = 80;
    D_5f5e[32]._0 = 1;
    D_5f5e[32]._c = 32;
    D_5c5a[32]._0_tile = D_5c5a[32]._1_animTile = 80;
    D_5c5a[32]._2_x = 17;
    assert(SLOTS_Write("999999", "Additional NPCs", NULL));
    NPC_ResetExtra();
    assert(SLOTS_Load("999999") && FILE_ReadSavegameFile("SAVED.GAM") == 0);
    assert(LOCATION_NPC_COUNT == 33 && D_5f5e[32]._c == 32 && D_5c5a[32]._2_x == 17);
    assert(SLOTS_Delete("999999"));
    NPC_ResetExtra();
    D_539c[0]=NULL;GRAP_Cleanup();SDL_Quit();
    puts("90+ named slots, party/world round trip, play time, failed overwrite, corrupt load and browser input passed");
    return 0;
}
