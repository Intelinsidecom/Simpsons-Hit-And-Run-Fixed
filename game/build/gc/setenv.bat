@echo off
REM Set CodeWarrior path (use short path format for build system)
set CWFOLDER=C:\PROGRA~2\METROW~1\CodeWarrior

REM Set Dolphin SDK path (adjust if installed elsewhere)
set DOLPHIN_ROOT=C:\DolphinSDK1.0

REM Set Dolphin platform
set DOLPHIN_PLATFORM=GCN

echo Environment variables set for GameCube build
echo CWFOLDER=%CWFOLDER%
echo DOLPHIN_ROOT=%DOLPHIN_ROOT%
echo DOLPHIN_PLATFORM=%DOLPHIN_PLATFORM%
