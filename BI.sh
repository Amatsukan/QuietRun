#!/bin/bash
CC="g++"
FLAGS="-std=c++11"
BIN="quietrun"
NICK="qr"
INSTALL=0
HELP=0
CLEAN=0

for i in "$@"
    do
    case $i in
        -h|--help)
            echo "For use: ./BI.sh (args)."

            echo "args:"

            echo "->   -d: or --debug, to build a debug version."
            echo "->   -v: or --verbose, use to built a program witch output functions, msg and more shits."
            echo "->   -o: or --stdout, use to enable stdout of your program and print."
            echo "->   -i: or --install, use as root to install this fucking software."
            echo "->   -c: or --clean, remove build program after install."

            echo "Installing..."
            echo "    ./BI.sh -c -i    or    ./BI.sh -i"

            echo "USE"

            echo "To use this fucking software-> quietrun [command and parameters] or qr [command and parameters]"
            echo "EX:"

            echo "    quietrun firefox"
            echo "    qr sudo rm -rf /"

            exit 0
        ;;
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
	    -c|--clean)
	        CLEAN=1
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
    
    if [ $CLEAN == 1 ]; then
	PWD=`pwd`
	if [ -f $PWD/quietrun ]; then
            rm -f $PWD/quietrun
            echo "Clean state"
	fi
    fi
fi
