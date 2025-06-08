#include "Header.h"

char SymbolInput(char c1, char c2) {
    char c;
    if (c1 == (char)0xD0 || c1 == (char)0xD1) {
        if (c1 == (char)0xD0 && c2 >= (char)0x90 && c2 <= (char)0xBF) {
            c = (char)0xC0 + (c2 - (char)0x90);
        }
        if (c1 == (char)0xD1 && (char)0x80 <= c2 && c2 <= (char)0x8F) {
            c = (char)0xF0 + (c2 - (char)0x80);
        }
        if (c1 == (char)0xD0 && c2 == (char)0x81) {
            c = (char)0xA8;
        }
        if (c1 == (char)0xD1 && c2 == (char)0x91) {
            c = (char)0xB8;
        }
    }
    else if (c >= (char)0 && c <= (char)127) {
        c = c1;
    }
    else {
        c = (char)255;
    }
    return c;  
}