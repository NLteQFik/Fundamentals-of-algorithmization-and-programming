#include "Header.h"

int NumberOfDigits(int n) {
    int counter = 1;
    while (n /= 10) {
        counter++;
    }
    return counter;
}