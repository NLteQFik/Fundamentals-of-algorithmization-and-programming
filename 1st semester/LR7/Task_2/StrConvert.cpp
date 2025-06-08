#include "Header.h"

void StrConvert(std::string& s) {
    int sign = 0;
    if (s[0] == '-') {
        s[0] = '0';
        sign = 1;
    }
    if (sign) {
        for (int i = 0; i < s.size(); i++) { // O(n)
            s[i] = '1' - s[i] + '0';
        }
        int n = s.size();
        s[n-1] += (char)1;
        for (int i = n - 1; i >= 0; i--) { // O(n)
            if (s[i] >= '2') {
                s[i] -= (char)2;
                s[i-1] += (char)1;
            }
            else {
                break;
            }
        }
    }
    if (!sign) {
        s.insert(0,1,'0');
    }
}