#!/bin/bash

cd "$(dirname "$BASH_SOURCE")"

rm ../JRTDE/src/main/java/de/dhbw/rahmlab/rtde/impl/*

echo "JAVA files cleared"

mkdir -p "../JRTDE/src/main/java/de/dhbw/rahmlab/rtde/impl/"


#-debug-tmsearch
swig -Wall -c++ -java -package de.dhbw.rahmlab.rtde.impl -outdir "../JRTDE/src/main/java/de/dhbw/rahmlab/rtde/impl/" -o rtde_wrap.cpp PlatformIndependent.i

echo "swig finished"
