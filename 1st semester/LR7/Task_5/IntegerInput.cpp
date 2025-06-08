#include "Header.h"

int IntegerInput() {
    int integer;
    std::cout << "Введите номер бочки, которую хотите отравить (не более 240):\n";
    while (true) {
        std::cin >> integer;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Вы читать не умеете? Тогда программа отравит бочку 121." << '\n';
            return 121;
        }
        if (std::cin.peek() != '\n') {
            std::cout << "Вы читать не умеете? Тогда программа отравит бочку 121." << '\n';
            std::cin.ignore(100000, '\n');
            return 121;
        }
        if (integer > 240 || integer < 1) {
            std::cout << "Вы читать не умеете? Тогда программа отравит бочку 121." << '\n';
            return 121;
        }
        break;
    }
    return integer;
}