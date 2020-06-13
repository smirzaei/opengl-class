#!/usr/bin/env bash
mkdir -p bin
gcc "$1" -o "bin/$1" -lGL -lGLU -lglut && ./bin/$1