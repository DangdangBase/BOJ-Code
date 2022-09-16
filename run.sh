#!/bin/bash

if [ -z $1 ]; then
  echo "please enter your file name!"
  exit
fi
 
g++ -std=c++17 -Wall $1.cpp -o $1.out
./$1.out
rm $1.out
