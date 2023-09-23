#!/bin/bash

mkdir -p build

gfortran -c sudoku/solveur.f90 -o build/solveur.o
gfortran -c sudoku/sudoku.f90 -o build/sudoku.o -I build/
gfortran -o build/sudokusolveur build/sudoku.o build/solveur.o

