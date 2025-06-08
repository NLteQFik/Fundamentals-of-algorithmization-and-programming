#include <iostream>

int IntegerInput() {
    int action;
    std::cout << "Введите число элементов одномерного массива (их должно быть не меньше 8).\n";
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
        if (action < 8) {
            std::cout << "Неверный формат ввода!" << '\n';
            continue;
        }
        break;
    }
    return action;
}