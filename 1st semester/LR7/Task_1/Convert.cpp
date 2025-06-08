#include "Header.h"

void Convert(std::string& s) {
    int n = s.size() - 1;
    for (int i = 0; i <= n; i++) { // O(n)
        if (s[n - i] == '0') {
            s[n - i] = '1';
            continue;
        }
        else {
            s[n - i] = '0';
            break;
        }
    }
}