#include "Header.h"

int Min(int a, int b, int type) {
    if (a <= b && -a <= b) {
        return a;
    }
    else {
        return b * (2 * type - 1);
    }
}