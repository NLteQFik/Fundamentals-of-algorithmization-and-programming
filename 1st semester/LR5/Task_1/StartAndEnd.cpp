#include <iostream>

int StartAndEnd() {
    int action;
    std::cout << "������� 1, ���� ������ ��������� ���������, ��� 2, ���� ������ ��������� ������ ���������.\n";
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
        if (action != 1 && action != 2) {
            std::cout << "�������� ������ �����!" << '\n';
            continue;
        }
        break;
    }
    return action;
}