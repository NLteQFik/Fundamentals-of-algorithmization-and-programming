#include "Header.h"

void SignInput(char& c) {
    std::cout << "Введите знак операции (+ или -):\n";
    while (true) {
        std::cin >> c;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!" << '\n';
            continue;
        }
        if (std::cin.peek() != '\n') {
            std::cout << "Неверный формат ввода!" << '\n';
            std::cin.ignore(100000, '\n');
            continue;
        }
        if (c != (char)'+' && c != (char)'-') {
            std::cout << "Неверный формат ввода!" << '\n';
            continue;
        }
        break;
    }
}