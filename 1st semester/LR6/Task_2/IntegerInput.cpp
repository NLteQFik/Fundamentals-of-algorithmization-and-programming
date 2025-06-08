#include "Header.h"

int IntegerInput() {
    int action;
    std::cout << "Введите целое положительное число - длину заменяемых слов.\n";
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
        if (action < 1) {
            std::cout << "Неверный формат ввода!" << '\n';
            continue;
        }
        break;
    }
    return action;
}