#include "Header.h"

int ArraySolve(char**& string, int string_size, int*& array_sizes) {
    for (int i = 0; i < string_size; i++) {
        Solve(string[i], array_sizes[i]);
    }
    return string_size;
}