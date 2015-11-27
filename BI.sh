#!/bin/bash
CC="g++"
FLAGS="-std=c++11"
BIN="quietrun"
NICK="qr"
INSTALL=0

for i in "$@"
    do
    case $i in
        -d|--debug)
            FLAGS+=" -ggdb -g3"
            echo "DEBUG BUILD"
        shift
        ;;
        -v|--verbose)
            FLAGS+=" -DENABLE_VERBOSE"
            echo "VERBOSE ENABLED"
        shift
        ;;
        -o|--stdout)
            FLAGS+=" -DENABLE_STDOUT -DENABLE_VERBOSE"
            echo "STDOUT ENABLED"
            shift
        ;;
        -i|--install)
            INSTALL=1
        ;;
        *)
                # unknown option
        ;;
    esac
done

$CC $FLAGS *.cpp *.h -o $BIN

echo "$BIN has been built"

if [ $INSTALL == 1 ]; then
    if [ "$(id -u)" != "0" ]; then
        echo "This script must be run as root to install this software" 1>&2
        exit 1
    fi

    echo "Installing..."
    cp $BIN /usr/bin/$BIN
    cp $BIN /usr/bin/$NICK

    echo "Install complete... =]"
fi
