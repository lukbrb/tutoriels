#!/bin/bash

set -xe 

mkdir -p build

gfortran -c solveur.f90 -o build/solveur.o
gfortran -c sudoku.f90 -o build/sudoku.o -I build/
gfortran -o build/sudokusolveur build/sudoku.o build/solveur.o
