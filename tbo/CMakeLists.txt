cmake_minimum_required(VERSION 3.22)
project(tbo C)

set(CMAKE_C_STANDARD 23)

add_executable(tbo main.c crivo.h crivo.c)
