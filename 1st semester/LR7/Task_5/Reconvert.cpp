#include "Header.h"

int Reconvert(std::string& s) {
    int n = 0;
    for (int i = 0; i < 5; i++) {
        n += (int)(s[i] - '0');
        n *= 3;
    }
    n /= 3;
    return n;
}