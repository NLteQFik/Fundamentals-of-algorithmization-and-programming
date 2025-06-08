#include "Header.h"

void DivisibilityCheck(long long number, int divisor) {
    int magic = (divisor + 1) >> 1;
    long long old_number = number;
    long long residue;
    do { // O(log n)
        old_number = number;
        if (number == 0 || number == divisor) {
            break;
        }
        if (number == ((number >> 1) << 1)) {
            residue = 0;
        }
        else {
            residue = 1;
        }
        if (residue) {
            number = (number >> 1) + magic;
        }
        else {
            number = (number >> 1);
        }
    } while (old_number > number);
    number = old_number;

    if (number == 0 || number == divisor) {
        std::cout << "Число делится на " << divisor << '\n';
    }
    else {
        std::cout << "Число не делится на " << divisor << '\n';
    }
}