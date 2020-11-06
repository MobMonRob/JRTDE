#!/bin/bash

cd "$(dirname "$BASH_SOURCE")"

#rm ../JRTDE/src/main/java/de/dhbw/rahmlab/rtde/impl/* &> /dev/null

./clear.sh

echo "JAVA files cleared"

mkdir -p "../JRTDE/src/main/java/de/dhbw/rahmlab/rtde/impl/"


#-Wall
#-debug-tmsearch
swig -Wextra -c++ -java -package de.dhbw.rahmlab.rtde.impl -outdir "../JRTDE/src/main/java/de/dhbw/rahmlab/rtde/impl/" -o rtde_wrap.cpp PlatformIndependent.i

echo "swig finished"

