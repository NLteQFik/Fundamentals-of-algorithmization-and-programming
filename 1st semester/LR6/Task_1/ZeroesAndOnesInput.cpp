#include "Header.h"

int ZeroesAndOnesInput(char* ptr, int size) {
    char symbol = 0;
    for (int i = 0; i < size - 1; i++) {
        symbol = getchar();
        if (symbol == '\n') {
            *(ptr + i) = '\0';
            return i + 1;
        }
        if (ZeroesAndOnesCheck(symbol)) {
            while (getchar() != '\n') {
            }
            return 0;
        }
        *(ptr + i) = symbol;
    }
    if (getchar() != '\n') {
        while (getchar() != '\n') {
        }
        return 0;
    }
    *(ptr + size - 1) = '\0';
    return size;
}