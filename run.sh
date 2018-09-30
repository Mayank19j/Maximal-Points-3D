#!/bin/sh

g++ maximal.cpp -o maxima
./maxima < $1 > $2

