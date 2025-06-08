#include <iostream>

int CheckForIntegerInput() {
    int integer;
    while (!(std::cin >> integer) || (std::cin.get() != '\n'))  {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return integer;
}

double CheckForRealInput() {
    double real;
    std::cin >> real;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return real;
}

void CheckOfInputOfRealMassive(double array[], int size) {
    array[size - 1] = -2000000000;
    while (1) {
        for (int i = 0; i < size; i++) {
            array[i] = CheckForRealInput();
            if (array[i] == -2000000000) {
                std::cout << "Неверный формат ввода.\n";
                break;
            }
        }
        if (array[size - 1] == -2000000000) {
            continue;
        }
        if (std::cin.peek() != '\n') {
            continue;
        }
        break;
    }
}

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа располагает элементы одномерного статического массива в обратном порядке.\n";
    std::cout << "Выполнил студент Арещенко Матвей, группа 453502, вариант 2.\n";
    while (true) {
        std::cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы.\n";
        int action = CheckForIntegerInput();
        if (action != 1 && action != 2) {
            std::cout << "Неверный формат ввода.\n";
            continue;
        }
        if (action == 2) {
            break;
        }
        const int size = 2;
        std::cout << "Введите одномерный массив из " << size << " чисел:\n";
        double array[size]{};
        do {
            CheckOfInputOfRealMassive(array, size);
        } while (array[size - 1] == -2000000000);
        std::cout << "Исходные данные:\n";
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << ' ';
        }
        std::cout << '\n';
        double save;
        for (int i = 0; i < size / 2; i++) {
            save = array[i];
            array[i] = array[size - 1 - i];
            array[size - 1 - i] = save;
        }
        std::cout << "Полученные данные:\n";
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}