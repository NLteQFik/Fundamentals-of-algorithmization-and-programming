#include "Header.h"

int StartAndEnd(int& cs) {
    int action;
    if (cs == 1) {
        std::cout << "Введите 1, если хотите отравить бочку, или 2, если не хотите.\n";
    }
    if (cs == 2) {
        std::cout << "Вы не хотите отравить бочку?" << '\n';
        std::cout << "Введите 1, если не хотите отравить бочку, или 2, если хотите.\n";
    }
    if (cs == 3) {
        std::cout << "Отравите бочку!!!" << '\n';
        std::cout << "Введите результат 51465 + 45856 * 425 - 54656, если не хотите отравить бочку.\n";
    }
    while (true) {
        std::cin >> action;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Программа воспринимает ваш бред как желание отравить бочку." << '\n';
            return 0;
        }
        if (std::cin.peek() != '\n') {
            std::cout << "Программа воспринимает ваш бред как желание отравить бочку." << '\n';
            std::cin.ignore(100000, '\n');
            return 0;
        }
        if (cs == 1) {
            if (action != 1 && action != 2) {
                std::cout << "Программа воспринимает ваш бред как желание отравить бочку." << '\n';
                return 0;
            }
        }
        if (cs == 2) {
            if (action != 1 && action != 2) {
                std::cout << "Программа воспринимает ваш бред как желание отравить бочку." << '\n';
                return 0;
            }
        }
        if (cs == 3) {
            if (action != 19485609) {
                std::cout << "Программа воспринимает ваш бред как желание отравить бочку." << '\n';
                return 0;
            }
            else {
                return 2;
            }
        }
        break;
    }
    return action;
}