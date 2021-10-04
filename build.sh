#!/bin/bash

rm main.bin
rm test.bin
g++ main.cpp -std=c++11 tree.cpp tree.h -o main.bin
g++ test.cpp -std=c++11 $(pkg-config --cflags --libs gtest)  -o test.bin
