#include <iostream>

int CheckForActionInput() {
    int integer;
    while (!(std::cin >> integer) || (std::cin.get() != '\n'))  {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return integer;
}

int CheckForIntegerInput() {
    int integer;
    std::cin >> integer;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return integer;
}

void CheckOfInputOfIntegerMassive(int* ptr, int size) {
    *(ptr + size - 1) = -2000000000;
    while (1) {
        for (int i = 0; i < size; i++) {
            *(ptr + i) = CheckForIntegerInput();
            if (*(ptr + i) == -2000000000) {
                std::cout << "Неверный формат ввода.\n";
                break;
            }
        }
        if (*(ptr + size - 1) == -2000000000) {
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
    std::cout << "Программа определяет количество отрицательных элементов, расположенных выше главной диагонали матрицы MxN.\n";
    std::cout << "Выполнил студент Арещенко Матвей, группа 453502, вариант 2.\n";
    while (true) {
        std::cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы.\n";
        int action = CheckForActionInput();
        if (action != 1 && action != 2) {
            std::cout << "Неверный формат ввода.\n";
            continue;
        }
        if (action == 2) {
            break;
        }
        const int m = 2;
        const int n = 3;
        const int size = m*n;
        std::cout << "Введите двумерный массив размером " << m << "x" << n << " чисел:\n";
        int array[m][n]{};
        int* pointer = *array;
        for (int i = 0; i < m; i++) {
            do {
                CheckOfInputOfIntegerMassive(pointer, n);
            } while (array[i][n - 1] == -2000000000);
            pointer += n;
        }
        pointer = nullptr;
        int counter;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                if (array[i][j] < 0) {
                    counter++;
                }
            }
        }
        std::cout << "Исходные данные:\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << array[i][j] << " ";
            }
            std::cout << '\n';
        }
        std::cout << "Количество отрицательных элементов, расположенных выше главной диагонали матрицы: " << counter << '\n';
        counter = 0;
    }
    return 0;
}