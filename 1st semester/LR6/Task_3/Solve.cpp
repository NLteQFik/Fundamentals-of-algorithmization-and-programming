#include "Header.h"

int Solve(char*& string, int& string_size) {
    int counter = 1;
    char symbol;
    int old_string_size;
    int number_of_digits = 6;
    for (int in = 1; in < string_size; in++) {
        if (string[in] == string[in - 1]) {
            counter++;
        }
        else {
            if (counter > 1) {
                symbol = string[in - 1];
                number_of_digits += NumberOfDigits(counter);
                if (counter < number_of_digits) {
                    old_string_size = string_size;
                    string_size += number_of_digits - counter;
                    string = (char*)realloc(string, string_size);
                    for (int j = old_string_size - 1; j >= in; j--) {
                        string[j + string_size - old_string_size] = string[j];
                    }
                    Fill(string, in - counter, number_of_digits, symbol, counter);
                    in += string_size - old_string_size;
                }
                if (counter > number_of_digits) {
                    old_string_size = string_size;
                    string_size += number_of_digits - counter;
                    for (int j = in; j < old_string_size; j++) {
                        string[j + string_size - old_string_size] = string[j];
                    }
                    Fill(string, in - counter, number_of_digits, symbol, counter);
                    string = (char*)realloc(string, string_size);
                    in += string_size - old_string_size;
                }
                if (counter == number_of_digits) {
                    Fill(string, in - counter, number_of_digits, symbol, counter);
                }
                number_of_digits = 6;
            }
            counter = 1;
        }
    }
    return string_size;
}