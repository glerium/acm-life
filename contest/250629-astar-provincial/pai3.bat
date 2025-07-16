@echo off
@REM g++ 3gen.cpp -o 3gen -Wall
@REM g++ 3.cpp -o 3 -Wall
@REM g++ 3_.cpp -o 3_ -Wall
@REM echo Compiled
3gen.exe
3.exe
3_.exe
fc out.txt ans.txt
echo %errorlevel%
@REM ping 127.0.0.1 -n 2
