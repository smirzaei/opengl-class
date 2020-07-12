#!/usr/bin/env bash
mkdir -p bin
gcc "$1" -o "bin/$1" -lm -lGL -lGLU -lglut && ./bin/$1