@echo off
echo Compiling Thread Library Project...

set src_dir=src
set build_dir=build

REM Create build directory if it doesn't exist
if not exist %build_dir% (
    mkdir %build_dir%
)

REM Compile each source file to an object file
echo Compiling source files...
gcc -c %src_dir%\thread.c -o %build_dir%\thread.o
gcc -c %src_dir%\sync_primitives.c -o %build_dir%\sync_primitives.o
gcc -c %src_dir%\main.c -o %build_dir%\main.o

REM Link object files into an executable
echo Linking object files...
gcc %build_dir%\thread.o %build_dir%\sync_primitives.o %build_dir%\main.o -o %build_dir%\thread_library.exe

echo Compilation complete. Executable created at %build_dir%\thread_library.exe
