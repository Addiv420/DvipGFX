#!/bin/bash
export LD_LIBRARY_PATH=.
rm -f ./DvipGFX
g++ main.cpp -L. -lvipgfx -o DvipGFX
./DvipGFX
