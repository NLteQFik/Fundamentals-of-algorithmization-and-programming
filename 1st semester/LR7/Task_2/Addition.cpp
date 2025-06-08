#include "Header.h"

void Addition(std::string& s1, std::string& s2) {
    StrConvert(s1); // O(n)
    StrConvert(s2); // O(n)

    if (s2.size() > s1.size()) {
        int alpha = s2.size() - s1.size();
        s1.insert(0,alpha,'0');
    }
    if (s1.size() > s2.size()) {
        int alpha = s1.size() - s2.size();
        if (s2[0] == '0') {
            s2.insert(0,alpha,'0');
        }
        else {
            s2.insert(0,alpha,'1');
        }
    }

    s1.insert(0,1,'0');
    int l1 = s1.size();
    int l2 = s2.size();

    for (int i = 0; i < s2.size(); i++) { // O(n)
        s1[l1 - 1 - i] += s2[l2 - 1 - i] - '0';
        if (s1[l1 - 1 - i] >= '2') {
            s1[l1 - 1 - i] -= (char)2;
            s1[l1 - 2 - i] += (char)1;
        }
    }

    if (s2[0] == '0') {
        Reconvert(s1, 0); // O(n)
    }
    else {
        Reconvert(s1, 1); // O(n)
    }


}