#include "Header.h"

int Solve(char*& string, char* sub_string, int& string_size, int sub_string_size, int length) {
    int i = 0;
    int counter = 0;
    int old_string_size;
    while (i <= string_size - 1) {
        if (*(string + i) == ' ' || *(string + i) == '\0') {
            if (counter == length) {
                if (length < sub_string_size - 1) {
                    old_string_size = string_size;
                    string_size += sub_string_size - 1 - length;
                    string = (char*)realloc(string, string_size);
                    for (int j = old_string_size - 1; j >= i; j--) {
                        string[j + string_size - old_string_size] = string[j];
                    }
                    for (int j = i - counter; j < sub_string_size - 1 + i - counter; j++) {
                        string[j] = sub_string[j - i + counter];
                    }
                    i += string_size - old_string_size;
                }
                if (length > sub_string_size - 1) {
                    old_string_size = string_size;
                    string_size += sub_string_size - 1 - length;
                    for (int j = i; j < old_string_size; j++) {
                        string[j + string_size - old_string_size] = string[j];
                    }
                    for (int j = i - counter; j < sub_string_size - 1 + i - counter; j++) {
                        string[j] = sub_string[j - i + counter];
                    }
                    string = (char*)realloc(string, string_size);
                    i += string_size - old_string_size;
                }
                if (length == sub_string_size - 1) {
                    for (int j = i - counter; j < sub_string_size - 1 + i - counter; j++) {
                        string[j] = sub_string[j - i + counter];
                    }
                    string = (char*)realloc(string, string_size);
                }
            }
            counter = 0; 
        }
        else {
            counter++;
        }
        i++;
    }
    return string_size;
}