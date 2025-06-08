#include "Header.h"

void Reconvert(std::string& s, int base, int type) {
    if (s[0] == (char)0 && type == 1) {
        s.erase(0, 1);
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

        for (int i = 0; i < s.size(); i++) { // O(n)
            if ((int)s[i] >= 10) {
                s[i] += '7';
            }
            else {
                s[i] += '0';
            }
        }

        if (s[0] == '0') {   
            s[0] = '-';
        }
    }
    else {
        s.erase(0, 1);

        for (int i = 0; i < s.size(); i++) { // O(n)
            if ((int)s[i] >= 10) {
                s[i] += '7';
            }
            else {
                s[i] += '0';
            }
        }

        while (s[0] == '0' && s.size() > 1) { // O(n)
            s.erase(0, 1);
        }
    }
}