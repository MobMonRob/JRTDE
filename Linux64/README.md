# Java-Wrapper für ViconDataStream

## Beschreibung
Dieses Projekt erzeugt einen Java Wrapper um die Vicon DataStream API unter `Ubuntu 18.04 x64` per `Bashskript`.

## Benötigte Software
* `Ubuntu 18.04 x64`
* git: `sudo apt-get install git`
* (empfohlen) dolphin git integration: `sudo apt-get install dolphin-plugins`
* openjdk-11 oder höher: `sudo apt-get install openjdk-11-jdk openjdk-11-demo openjdk-11-doc openjdk-11-jre-headless openjdk-11-source`
* gcc und make: `sudo apt-get install build-essential`
* PCRE Bibliothek (für SWIG): `sudo apt-get install libpcre3 libpcre3-dev`
* [SWIG 4.0.1](http://www.swig.org/download.html)
    * `cd ./swig-4.0.1`
    * `./configure`
    * `make`
    * `sudo make install`
    * SWIG 3.x does not work
    * siehe: https://github.com/swig/swig/wiki/Getting-Started
* [Netbeans 12 LTS](https://netbeans.apache.org/download/nb120/nb120.html)

## Dateien generieren
Projekt in `git pull`en.\
Mit Klick auf die `wrapper_so_generator.sh` Datei im Projektverzeichnis unter `/Linux64` den Prozess anstoßen.

Die Java Dateien befinden sich jetzt in `JViconDataStreamTest` und die `.so` Datei in `/Linux64`.

