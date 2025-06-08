#include "Header.h"

int SignCheck(std::string& s1, std::string& s2) {
    if (s1[0] == '-') {
        s1.erase(0, 1);
        if (s2[0] == '-') {
            s2.erase(0, 1);
        }
        else {
            s2.insert(0, 1, '-');
        }
        return 1;
    }
    else {
        return 0;
    }
}