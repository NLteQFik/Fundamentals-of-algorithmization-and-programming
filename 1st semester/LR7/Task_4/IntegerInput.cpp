#include "Header.h"

long long IntegerInput() {
    long long action;
    std::cout << "Введите целое число.\n";
    while (true) {
        std::cin >> action;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Неверный формат ввода!" << '\n';
            continue;
        }
        if (std::cin.peek() != '\n') {
            std::cout << "Неверный формат ввода!" << '\n';
            std::cin.ignore(10000, '\n');
            continue;
        }
        if (action < 0) {
            std::cout << "Неверный формат ввода!" << '\n';
            continue;
        }
        break;
    }
    return action;
}