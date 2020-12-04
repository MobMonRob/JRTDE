#!/bin/bash

cd "$(dirname "$BASH_SOURCE")"

./clear.sh

../swig/generate_test.sh

#https://web.archive.org/web/20201007174747/https://stackoverflow.com/questions/54373254/load-dependent-so-from-other-shared-library-via-jni/58842312#58842312
# -rpath,'$ORIGIN/.' --> ad the folder where the so-file resides into the search path for dependend libs
/usr/bin/g++-7 -shared -fPIC -cpp -std=c++1z -O3 -flto ../swig/rtde_wrap.cpp -Llibs -lurcl -o libjrtde.so -I/usr/lib/jvm/default-java/include -I/usr/lib/jvm/default-java/include/linux -I. -Wl,-rpath,'$ORIGIN/.'

echo "gcc finished"

#Has to be: <Project Folder>/natives/<os-arch> !!
mkdir -p ../JRTDE/natives/linux-amd64/
cp ./*.so* ../JRTDE/natives/linux-amd64/
cp ./build/*.so* ../JRTDE/natives/linux-amd64/

# WORKAROUND
sudo cp libjrtde.so /usr/java/packages/lib

echo "Linux64 finished"

