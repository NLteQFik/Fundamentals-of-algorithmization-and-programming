#include "Header.h"

int ArrayStringOutput(char** string, int string_size, int* array_sizes) {
    for (int i = 0; i < string_size; i++) {
        StringOutput(string[i], array_sizes[i]);
        std::cout << '\n';
    }
    return string_size;
}