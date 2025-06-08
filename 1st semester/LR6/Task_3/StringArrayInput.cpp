#include "Header.h"

int StringArrayInput(char**& ptr, int size, int*& array_sizes) {
    char buffer[size];
    int string_size;
    int str_arr_size = 0;
    while (string_size = BufferInput(buffer, size) - 1) {
        if (string_size == -1) {
            std::cout << "Неверный формат ввода!\n";
            continue;
        }
        string_size++;
        str_arr_size++;
        ptr = (char**)realloc(ptr, str_arr_size * sizeof(char*));
        ptr[str_arr_size - 1] = (char*)malloc(string_size * sizeof(char));
        array_sizes = (int*)realloc(array_sizes, str_arr_size * sizeof(char*));
        array_sizes[str_arr_size - 1] = string_size;
        for (int i = 0; i < string_size; i++) {
            ptr[str_arr_size - 1][i] = buffer[i]; 
        } 
    }
    return str_arr_size;

}