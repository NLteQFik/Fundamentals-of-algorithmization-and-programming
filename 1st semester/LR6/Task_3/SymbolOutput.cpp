#include "Header.h"

char SymbolOutput(char c) {
    char c1, c2;       
    if (c == (char)0xB8) {
        c1 = (char)0xD1;
        c2 = (char)0x91;
    }
    if (c == (char)0xA8) {
        c1 = (char)0xD0;
        c2 = (char)0x81;
    }
    if (c >= (char)0xC0 && c <= (char)0xEF) {
        c1 = (char)0xD0;
        c2 = (char)0x90 + (c - (char)0xC0);
    }
    if (c >= (char)0xF0 && c <= (char)0xFF) {
        c1 = (char)0xD1;
        c2 = (char)0x80 + (c - (char)0xF0);
    }
    std::cout << c1 << c2;
    return c;
}