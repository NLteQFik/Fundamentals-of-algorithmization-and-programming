#include <iostream>

int IntegerInput(int a) {
    int action;
    if (a) {
        std::cout << "������� ����� n.\n";
    }
    else {
        std::cout << "������� ����� k.\n";
    }
    while (true) {
        std::cin >> action;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "�������� ������ �����!" << '\n';
            continue;
        }
        if (std::cin.peek() != '\n') {
            std::cout << "�������� ������ �����!" << '\n';
            std::cin.ignore(10000, '\n');
            continue;
        }
        if (action < 1) {
            std::cout << "�������� ������ �����!" << '\n';
            continue;
        }
        break;
    }
    return action;
}