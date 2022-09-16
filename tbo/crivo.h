//
// Created by user on 9/16/2022.
//

#ifndef TBO_CRIVO_H
#define TBO_CRIVO_H

#include <stdlib.h>
#include <stdbool.h>
/*
 * Marks with 1 numbers that are not prime
 */
void mark(char* arr, int size, int curr);
/*
 * Returns -1 if not found
 */
int find_unmarked(char* arr, int size, int curr);

#endif //TBO_CRIVO_H
