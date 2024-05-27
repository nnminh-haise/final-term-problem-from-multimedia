@echo off
title Final Term Problems builder
if not exist build mkdir build
robocopy "./src/problem-1/data" "./build/output/debug" /E
cd build
cmake ..
cmake --build .
pause