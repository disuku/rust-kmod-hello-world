cmake_minimum_required(VERSION 3.13)
add_library(rust-kmod-hello-world OBJECT src-ko/hello.c src-ko/device_control.c)
target_include_directories(rust-kmod-hello-world PUBLIC /usr/src/linux-headers-4.15.0-45/include)