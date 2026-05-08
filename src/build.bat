@echo off
set OLDPATH=%PATH%

set PATH=%PATH%;C:\MASM611\BIN

call C:\MSC51\BIN\MSCVARS.BAT
rem call C:\C600\BIN\MSCVARS.BAT
rem call C:\MSVC\BIN\MSVCVARS.BAT

set CFLAGS=/Ox /Or /Gs /Gc /Zp /c /Fa

rem disable loop optimization?
set CFLAGS_ULTIMA=/Oaitr /Or /Gs /Gc /Zp /c /Fa
set AS=\TOOLS\MASM611
set CL=CL
set LINK=\tools\link531

echo START > log.txt

del *.obj

rem %CL% %CFLAGS% town.c >> log.txt
rem %CL% %CFLAGS% mainout.c >> log.txt
rem %CL% %CFLAGS% dungeon.c >> log.txt
rem %CL% %CFLAGS% intro.c >> log.txt
rem %CL% %CFLAGS% npc.c >> log.txt
rem %CL% %CFLAGS% combat.c >> log.txt
rem %CL% %CFLAGS% blckthrn.c >> log.txt
rem %CL% %CFLAGS% lookobj.c >> log.txt
rem %CL% %CFLAGS% dnglook.c >> log.txt
rem %CL% %CFLAGS% outsubs.c >> log.txt
rem %CL% %CFLAGS% shoppes.c >> log.txt
rem %CL% %CFLAGS% endgame.c >> log.txt
rem %CL% %CFLAGS% sjog.c >> log.txt
%CL% %CFLAGS% cmds.c >> log.txt
rem %CL% %CFLAGS% cast.c >> log.txt
rem %CL% %CFLAGS% talk.c >> log.txt
rem %CL% %CFLAGS% cast2.c >> log.txt
rem %CL% %CFLAGS% zstats.c >> log.txt
rem %CL% %CFLAGS% comsubs.c >> log.txt
rem %CL% %CFLAGS% shoppes2.c >> log.txt
rem %CL% %CFLAGS% shoppes3.c >> log.txt
rem %CL% %CFLAGS% font.c >> log.txt
rem 
rem %CL% %CFLAGS% vars.c >> log.txt
rem %CL% %CFLAGS% file.c >> log.txt
rem %CL% %CFLAGS_ULTIMA% ultima.c >> log.txt
rem %CL% %CFLAGS% grap.c >> log.txt
rem 
rem %CL% %CFLAGS% 0000.c >> log.txt
rem %CL% %CFLAGS% 1000.c >> log.txt
rem %CL% %CFLAGS% 2000.c >> log.txt
rem %CL% %CFLAGS% 3000.c >> log.txt
rem %CL% %CFLAGS% 4000.c >> log.txt
rem %CL% %CFLAGS% 5000.c >> log.txt
rem %CL% %CFLAGS% 6000.c >> log.txt
rem %CL% %CFLAGS% 7000.c >> log.txt

rem %LINK% /MAP @u5.rsp >> log.txt

rem type log.txt

set PATH=%OLDPATH%
set OLDPATH=
