#include "Header.h"

int StringInput(char*& ptr, int size) {
    if (size == 1) {
        return 0;
    }
    char buffer[size - 1];
    int buf_size = 0;
    int string_size = 0;
    while (!((buf_size = BufferInput(buffer, size)) - size)) {
        string_size += size - 1;
        ptr = (char*)realloc(ptr, string_size);
        for (int i = 0; i < size - 1; i++) {
            ptr[string_size - size + 1 + i] = buffer[i];
        }
    }
    string_size += buf_size;
    ptr = (char*)realloc(ptr, string_size);
    for (int i = 0; i < buf_size; i++) {
        ptr[string_size - buf_size + i] = buffer[i];
    }
    return string_size;
}