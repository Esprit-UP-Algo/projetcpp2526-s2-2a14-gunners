@echo off
REM Set up Qt environment
set CMAKE_PREFIX_PATH=C:\Qt\6.7.3\mingw_64
set PATH=C:\Qt\6.7.3\mingw_64\bin;C:\Qt\Tools\mingw1120_64\bin;%PATH%
set QT_PLUGIN_PATH=C:\Qt\6.7.3\mingw_64\plugins
set QML_IMPORT_PATH=C:\Qt\6.7.3\mingw_64\qml

REM Go to build directory
cd /d "c:\Users\Akram\Desktop\metier avance akram\smart_research3\build\Desktop_Qt_6_7_3_MinGW_64_bit-Debug"

REM Clean build artifacts
if exist "debug" (
    echo Cleaning build directory...
    del /q Makefile.Debug Makefile.Release Makefile 2>nul
    rmdir /s /q debug 2>nul
)

REM Run qmake
echo Generating Makefiles...
C:\Qt\6.7.3\mingw_64\bin\qmake.exe -spec win32-g++ ..\..\SmartResearch.pro

REM Build with mingw32-make
echo.
echo Building project...
C:\Qt\Tools\mingw1120_64\bin\mingw32-make.exe -f Makefile.Debug 2>&1

echo.
echo Build complete. Check output above for errors.
pause
