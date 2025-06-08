#include "Header.h"

int StringOutput(char* string, int size) {
    char symbol = 0;
    for (int i = 0; i < size; i++) {
        symbol = *(string + i);
        if (symbol >= (char)0 && symbol <= (char)127) {
            std::cout << symbol;
        }
        else if (symbol == (char)0xB8 || symbol == (char)0xA8 || (symbol >= (char)0xC0 && symbol <= (char)0xFF)) {
            SymbolOutput(symbol);
        }
        else {
            return 0;
        }
    }
    return size;
}