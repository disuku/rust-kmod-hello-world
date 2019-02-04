# Hello World Rust Kernel Module

## Dependencies

 - build-essential (Ubuntu)

## Building

`$ ./build.sh`

## Loading into kernel

`# insmod ./build/myhello.ko`

## Removing from Kernel

`# rmmod myhello`

## All at once
`$ ./build.sh && sudo insmod ./build/myhello.ko && sudo rmmod myhello`
