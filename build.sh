#!/bin/sh


# -e : Exit immediately if a command exits with a non-zero status.
# -x : Print commands and their arguments as they are executed.
set -xe

clang -Wall -Wextra -ggdb -o main main.c
