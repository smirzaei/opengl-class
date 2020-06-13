#!/usr/bin/env bash
mkdir -p bin
gcc "$1" -o "bin/$1" & ./bin/$1