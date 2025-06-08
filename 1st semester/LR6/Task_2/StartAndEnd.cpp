#include "Header.h"

int StartAndEnd() {
    int action;
    std::cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы.\n";
    while (true) {
        std::cin >> action;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Неверный формат ввода" << '\n';
            continue;
        }
        if (std::cin.peek() != '\n') {
            std::cout << "Неверный формат ввода!" << '\n';
            std::cin.ignore(10000, '\n');
            continue;
        }
        if (action != 1 && action != 2) {
            std::cout << "Неверный формат ввода!" << '\n';
            continue;
        }
        break;
    }
    return action;
}