@ECHO OFF

if exist build rmdir build /q /s

mkdir build

cmake -S . -B build -G "MinGW Makefiles"

cmake --build build

PAUSE
