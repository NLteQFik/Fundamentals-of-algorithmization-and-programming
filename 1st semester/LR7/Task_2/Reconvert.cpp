#include "Header.h"

void Reconvert(std::string& s, int type) {
    if (s[0] == '0' && type == 1) {
        s.erase(0, 1);
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

        
        if (s[0] == '0') {   
            s[0] = '-';
            while (s[1] == '0' && s.size() > 2) { // O(n)
                s.erase(1, 1);
            }
        }
    }
    else {
        s.erase(0, 1);

        while (s[0] == '0' && s.size() > 1) { // O(n)
            s.erase(0, 1);
        }
    }
}