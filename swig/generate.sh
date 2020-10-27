#!/bin/bash

cd "$(dirname "$BASH_SOURCE")"

rm ../JRTDE/src/main/java/de/dhbw/rahmlab/RTDE/impl/*

echo "JAVA files cleared"

mkdir -p "../JRTDE/src/main/java/de/dhbw/rahmlab/RTDE/impl/"


#-debug-tmsearch
swig -Wall -c++ -java -package de.dhbw.rahmlab.RTDE.impl -outdir "../JRTDE/src/main/java/de/dhbw/rahmlab/RTDE/impl/" -o RTDE_wrap.cpp PlatformIndependent.i

echo "swig finished"
