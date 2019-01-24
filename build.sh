#!/usr/bin/env bash

rm -rf build
cp -r src build
(cd build;
g++ -c -o lib.o lib.c
make
)
