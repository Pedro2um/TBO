//
// Created by user on 9/16/2022.
//

#ifndef TBO_CRIVO_H
#define TBO_CRIVO_H

#include <stdlib.h>
#include <stdbool.h>
typedef long long unsigned llu;
/*
 * Marks with 1 numbers that are not prime
 */
void mark(char* arr, llu size, llu curr);
/*
 * Returns 0 if not found
 */
llu find_unmarked(char* arr, llu size, llu curr);

#endif //TBO_CRIVO_H