#!/bin/bash

if [ ! -d bin ] then
    mkdir bin
fi

g++ -std=c++11 -Wall src/problem$1.cpp -o bin/problem$1
echo "Compiled src/problem$1.cpp to bin/problem$1" 
