@echo off
@REM g++ 5gen.cpp -o 5gen -Wall
@REM g++ 5.cpp -o 5 -Wall
@REM g++ 5_.cpp -o 5_ -Wall
@REM echo Compiled
5gen.exe
5.exe
5_.exe
fc out.txt ans.txt
echo %errorlevel%
@REM ping 127.0.0.1 -n 2
