#!/bin/bash
CC="g++"
FLAGS="-std=c++11"
#FLAGS=" -DENABLE_VERBOSE"
#FLAGS+=" -DENABLE_STDOUT"
BIN="quietrun"
NICK="qr"

if [ "$1" == "-d" ]; then
    FLAGS+=" -ggdb -g3"
    echo "DEBUG BUILD"
fi

$CC $FLAGS *.cpp *.h -o $BIN
echo "$BIN has been built"

if [ "$(id -u)" != "0" ]; then
   echo "This script must be run as root to install this software" 1>&2
   exit 1
fi

cp $BIN /usr/bin/$BIN
cp $BIN /usr/bin/$NICK

echo "Install complete... =]"
