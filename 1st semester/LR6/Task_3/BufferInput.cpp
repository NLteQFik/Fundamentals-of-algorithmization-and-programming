#include "Header.h"

int BufferInput(char* ptr, int size) {
    char symbol = 0;
    for (int i = 0; i < size - 1; i++) {
        symbol = getchar();
        if (symbol == '\n') {
            *(ptr + i) = '\0';
            return i + 1;
        }
        else if (symbol >= (char)0 && symbol <= (char)127) {
            *(ptr + i) = symbol;
        }
        else if (symbol == (char)0xD0 || symbol == (char)0xD1) {
            char symbol2 = getchar();
            symbol2 = SymbolInput(symbol, symbol2);
            if (symbol2 == (char)0) {
                return 0;
            }
            *(ptr + i) = symbol2;
        }
        else {
            return 0;
        }
    }
    if (symbol != '\n') {
        while (getchar() != '\n') {
        }
        return 0;
    }
    else {
        *(ptr + size - 1) = '\0';
    }
    return size;
}