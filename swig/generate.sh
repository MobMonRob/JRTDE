#!/bin/bash

cd "$(dirname "$BASH_SOURCE")"



mkdir -p "../JRTDE/src/main/java/de/dhbw/rahmlab/rtde/impl/"


#-debug-tmsearch
swig -Wall -c++ -java -package de.dhbw.rahmlab.rtde.impl -outdir "../JRTDE/src/main/java/de/dhbw/rahmlab/rtde/impl/" -o RTDE_wrap.cpp PlatformIndependent.i

echo "swig finished"

