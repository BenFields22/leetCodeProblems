#!/bin/zsh
g++ --std=c++11 ./parseInputList.cpp -o run 
cat ./input.txt | ./run 
