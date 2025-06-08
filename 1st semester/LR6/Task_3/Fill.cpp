#include "Header.h"

int Fill(char*& string, int i, int size, char symbol, int counter) {
    int tn = (int)symbol;
    if (tn < 0) {
        tn += 256;
    }
    string[i] = '2';
    string[i + 1] = '5';
    string[i + 2] = '5';
    string[i + 3] = (char)(tn / 100 + 48);
    string[i + 4] = (char)((tn / 10) % 10 + 48);
    string[i + 5] = (char)(tn % 10 + 48);
    for (int j = size - 1; j >= 6; j--) {
        string[i + j] = (char)(counter % 10 + 48);
        counter /= 10;
    }
    return i;
}