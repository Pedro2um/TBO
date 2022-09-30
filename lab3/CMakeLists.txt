cmake_minimum_required(VERSION 3.22)
project(lab3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lab3
        item.h
        main.c select_sort.c)
