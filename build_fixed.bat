@echo off
setlocal enabledelayedexpansion

REM Set Qt environment
set CMAKE_PREFIX_PATH=C:\Qt\6.7.3\mingw_64
set PATH=C:\Qt\6.7.3\mingw_64\bin;C:\Qt\Tools\mingw1120_64\bin;C:\Qt\Tools\mingw1120_64\x86_64-w64-mingw32\bin;%PATH%
set QT_PLUGIN_PATH=C:\Qt\6.7.3\mingw_64\plugins
set QML_IMPORT_PATH=C:\Qt\6.7.3\mingw_64\qml

REM Go to project directory
cd /d "c:\Users\Akram\Desktop\metier avance akram\smart_research3"

echo Cleaning old build...
rmdir /s /q build 2>nul

mkdir build
cd build

echo.
echo ========================================
echo Generating Makefiles with qmake...
echo ========================================
call C:\Qt\6.7.3\mingw_64\bin\qmake.exe -spec win32-g++ "..\SmartResearch.pro"

if %ERRORLEVEL% NEQ 0 (
    echo ERROR: qmake failed!
    pause
    exit /b 1
)

echo.
echo ========================================
echo Building project...
echo ========================================
call C:\Qt\Tools\mingw1120_64\bin\mingw32-make.exe -f Makefile.Debug

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================
    echo BUILD SUCCESSFUL!
    echo ========================================
    dir /s debug\SmartResearch.exe 2>nul || echo Warning: exe not found
) else (
    echo.
    echo ========================================
    echo BUILD FAILED - see errors above
    echo ========================================
)

cd ..
pause
