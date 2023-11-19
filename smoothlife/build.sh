#!/bin/sh

set -xe

CC="${CXX:-cc}"

$CC -O3 -Wall -Wextra -o main main.c -lm
