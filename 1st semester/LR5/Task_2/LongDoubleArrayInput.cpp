#include <iostream>

extern "C" void __declspec(dllexport) __stdcall LongDoubleArrayInput(long double* ptr, int size) {
    std::cout << "������� ���������� ������ X �� " << size << " ����� � ������.\n";
    bool b;
    while (true) {
        b = 0;
        for (int i = 0; i < size; i++) {
            std::cin >> *(ptr + i);
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                b = 1;
                break;
            }
            if (i == size - 1) {
                break;
            }
            if (std::cin.peek() == '\n') {
                b = 1;
                break;
            }
            if (std::cin.get() != ' ') {
                std::cin.ignore(10000, '\n');
                b = 1;
                break;
            }
        }
        if (b) {
            std::cout << "�������� ������ �����!\n";
            continue;
        }
        if (std::cin.peek() != '\n') {
            std::cin.ignore(10000, '\n');
            std::cout << "�������� ������ �����!\n";
            continue;
        }
        break;
    }
}