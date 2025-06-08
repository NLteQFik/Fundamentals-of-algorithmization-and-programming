#include "Header.h"

void Subtraction(std::string& s1, std::string& s2, int base) {
    if (s2[0] == '-') {
        s2.erase(0, 1);
    }
    else {
        if (s2[0] != '0') {
            s2.insert(0, 1, '-');
        }
    }

    Addition(s1, s2, base); // O(n)
}