#include "Header.h"

int FindShortAndType(char* ptr, int size) {
    int shortest = 1000;
    int counter = 1;
    int type = 0;
    if (size == 1) {
        return 0;
    }
    for (int i = 1; i < size; i++) {
        if (*(ptr + i) == *(ptr + i - 1)) {
            counter++;
        }
        else {
            type = *(ptr + i - 1) - '0';
            shortest = Min(shortest,counter,type);
            counter = 1;
        }
    }
    return shortest;
}