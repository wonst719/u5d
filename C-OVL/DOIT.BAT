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

%CL% %CFLAGS% town.c >> log.txt
%CL% %CFLAGS% mainout.c >> log.txt
%CL% %CFLAGS% dungeon.c >> log.txt
%CL% %CFLAGS% intro.c >> log.txt
%CL% %CFLAGS% npc.c >> log.txt
%CL% %CFLAGS% blckthrn.c >> log.txt
%CL% %CFLAGS% dnglook.c >> log.txt
%CL% %CFLAGS% outsubs.c >> log.txt
%CL% %CFLAGS% sjog.c >> log.txt
%CL% %CFLAGS% talk.c >> log.txt
%CL% %CFLAGS% zstats.c >> log.txt
%CL% %CFLAGS% vars.c >> log.txt
%CL% %CFLAGS% stubs.c >> log.txt
%CL% %CFLAGS% file.c >> log.txt
%CL% %CFLAGS_ULTIMA% ultima.c >> log.txt
%CL% %CFLAGS% grap.c >> log.txt
%CL% %CFLAGS% grap_drv.c >> log.txt
%CL% %CFLAGS% 0000.c >> log.txt
%CL% %CFLAGS% 1000.c >> log.txt
%CL% %CFLAGS% 2000.c >> log.txt
%CL% %CFLAGS% 3000.c >> log.txt
%CL% %CFLAGS% 4000.c >> log.txt
%CL% %CFLAGS% 5000.c >> log.txt
%CL% %CFLAGS% 6000.c >> log.txt
%CL% %CFLAGS% 7000.c >> log.txt

%LINK% /MAP @u5.rsp >> log.txt

type log.txt

set PATH=%OLDPATH%
set OLDPATH=
