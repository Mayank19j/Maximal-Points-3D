#!/bin/sh

make clean
make all
./maximal $1 $2
