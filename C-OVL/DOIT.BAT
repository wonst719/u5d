@echo off
set OLDPATH=%PATH%

set PATH=%PATH%;C:\MASM611\BIN

call C:\MSC51\BIN\MSCVARS.BAT
rem call C:\C600\BIN\MSCVARS.BAT
rem call C:\MSVC\BIN\MSVCVARS.BAT

set CFLAGS=/Ox /Gs /Gc /Zp /c /Fa
set AS=\TOOLS\MASM611
set CL=CL

echo START > log.txt

del *.obj

%CL% %CFLAGS% zstats.c >> log.txt

type log.txt

set PATH=%OLDPATH%
set OLDPATH=
