#include "Header.h"

void Convert(std::string &s, int num) {
    for (int i = 0; i < 5; i++) {
        int res = num % 3;
        s.insert(0,1,(char)(48 + res));
        num /= 3;
    }
}