#include "Header.h"

void StrConvert(std::string& s, int base) {
    int sign = 0;
    if (s[0] == '-') {
        s[0] = '0';
        sign = 1;
    }
    for (int i = 0; i < s.size(); i++) { // O(n)
        if ((int)s[i] >= 65) {
            s[i] -= '7';
        }
        else {
            s[i] -= '0';
        }
    }
    if (sign) {
        for (int i = 0; i < s.size(); i++) { // O(n)
            s[i] = (char)(base - 1 - (int)s[i]);
        }
        int n = s.size();
        s[n-1] += (char)1;
        for (int i = n - 1; i >= 0; i--) { // O(n)
            if (s[i] >= (char)base) {
                s[i] -= (char)base;
                s[i-1] += (char)1;
            }
            else {
                break;
            }
        }
    }
    if (!sign) {
        s.insert(0,1,(char)0);
    }
}