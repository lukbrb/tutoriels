#!/bin/bash

mkdir -p build
echo "gfortran -c solveur.f90"
gfortran -c solveur.f90 -o build/solveur.o
echo "gfortran -c sudoku.f90 -o build/sudoku.o -I build/"
gfortran -c sudoku.f90 -o build/sudoku.o -I build/
echo "gfortran -o sudokusolveur build/sudoku.o build/solveur.o"
gfortran -o build/sudokusolveur build/sudoku.o build/solveur.o

