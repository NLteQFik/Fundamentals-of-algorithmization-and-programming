#include <iostream>

void LongDoubleArrayInput(long double** ptr, int n, int k) {
    std::cout << "Введите массив A из " << n << "x" << k << " чисел построчно.\n";
    bool b;
    b = 0;
    for (int i = 0; i < n; i++) {
        while (true) {
            for (int j = 0; j < k; j++) {
                b = 0;
                std::cin >> *(*(ptr + i) + j);
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    b = 1;
                    break;
                }
                if (j == k - 1) {
                    break;
                }
                if (std::cin.peek() == '\n') {
                    b = 1;
                    break;
                }
                if (std::cin.get() != ' ') {
                    std::cin.ignore(10000, '\n');
                    b = 1;
                    break;
                }
            }
            if (b) {
                std::cout << "Неверный формат ввода!\n";
                continue;
            }
            if (std::cin.peek() != '\n') {
                std::cin.ignore(10000, '\n');
                std::cout << "Неверный формат ввода!\n";
                continue;
            }
            break;
        }
    }
}