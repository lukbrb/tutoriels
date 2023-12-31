#!/bin/bash

set -xe

FFLAGS="-std=f2003 -fno-range-check -Wall -Wextra -Wno-conversion"
LIBS="-framework IOKit -framework Cocoa -framework OpenGL $(pkg-config --libs --cflags raylib)"
SRC="src/c-interface.f90 app/main.f90"

mkdir -p build/
gfortran $FFLAGS -J build/ -o build/tictactoe $SRC $LIBS