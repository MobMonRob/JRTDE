#!/bin/bash

cd "$(dirname "$BASH_SOURCE")"

./clear.sh

../swig/generate.sh

#https://web.archive.org/web/20201007174747/https://stackoverflow.com/questions/54373254/load-dependent-so-from-other-shared-library-via-jni/58842312#58842312
gcc -shared -fPIC -cpp -std=c++17 -O3 -flto ../swig/rtde_wrap.cpp -Lbuild -lrtde -o libjrtde.so -I/usr/lib/jvm/default-java/include -I/usr/lib/jvm/default-java/include/linux -Wl,-rpath,'$ORIGIN/.'

echo "gcc finished"

#Has to be: <Project Folder>/natives/<os-arch> !!
mkdir -p ../JRTDE/natives/linux-amd64/
cp ./*.so* ../JRTDE/natives/linux-amd64/
cp ./build/*.so* ../JRTDE/natives/linux-amd64/

echo "Linux64 finished"

