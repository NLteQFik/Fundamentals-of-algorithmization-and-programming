#include "Header.h"

int IntegerInput() {
    int integer;
    std::cout << "Введите основание системы счисления (не более 36):\n";
    while (true) {
        std::cin >> integer;
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
        if (integer > 36 || integer < 2) {
            std::cout << "Неверный формат ввода!" << '\n';
            continue;
        }
        break;
    }
    return integer;
}