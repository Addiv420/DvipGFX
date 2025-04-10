#!/bin/bash
export LD_LIBRARY_PATH=.
rm -f ./Linux
g++ main.cpp -L. -lvipgfx -o draw
./draw
