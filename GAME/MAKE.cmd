@echo off
color 1F
chcp 65001>nul
title MAKE PS3 PROJECT BY KIOSENSEY
setlocal enabledelayedexpansion

set PS3SDK=/c/PSDK3v2
set WIN_PS3SDK=C:/PSDK3v2
set PATH=%WIN_PS3SDK%/mingw/msys/1.0/bin;%WIN_PS3SDK%/mingw/bin;%WIN_PS3SDK%/ps3dev/bin;%WIN_PS3SDK%/ps3dev/ppu/bin;%WIN_PS3SDK%/ps3dev/spu/bin;%WIN_PS3SDK%/mingw/Python27;%PATH%;
set PSL1GHT=%PS3SDK%/psl1ght
set PS3DEV=%PS3SDK%/ps3dev

C:\PSDK3v2\MinGW\msys\1.0\bin\make clean
C:\PSDK3v2\MinGW\msys\1.0\bin\make
if exist *.elf del *.elf
title END.

color 2F
pause