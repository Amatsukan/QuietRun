#!/bin/bash
CC="g++"
FLAGS="-std=c++11 -O3"
BIN="quietrun"
NICK="qr"

i$CC $FLAGS quietrun.cpp -o $BIN
echo "$BIN has been built"

if [ "$(id -u)" != "0" ]; then
   echo "This script must be run as root to install this software" 1>&2
   exit 1
fi

cp $BIN /usr/bin/$BIN
cp $BIN /usr/bin/$NICK

echo "Install complete... =]"
