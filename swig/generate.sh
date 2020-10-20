#!/bin/bash

cd "$(dirname "$BASH_SOURCE")"



mkdir -p "../JAVA/src/main/java/de/dhbw/rahmlab/RTDE/impl/"


#-debug-tmsearch
swig -Wall -c++ -java -package de.dhbw.rahmlab.RTDE.impl -outdir "../JAVA/src/main/java/de/dhbw/rahmlab/RTDE/impl/" -o RTDE_wrap.cpp PlatformIndependent.i

echo "swig finished"

