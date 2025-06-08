#include <iostream>

extern "C" int __declspec(dllexport) __stdcall IntegerInput() {
    int action;
    std::cout << "������� ����� N ��������� ����������� �������.\n";
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
        if (action <= 0) {
            std::cout << "�������� ������ �����!" << '\n';
            continue;
        }
        break;
    }
    return action;
}