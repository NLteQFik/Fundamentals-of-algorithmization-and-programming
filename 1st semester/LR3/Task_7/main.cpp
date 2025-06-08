#include <iostream>
#include <cmath>

int CheckForIntegerInput() {
    int integer;
    while (!(std::cin >> integer) || (std::cin.get() != '\n'))  {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return integer;
}

int NumberOfDigits(int n) {
    int counter = 0;
    while (n > 0) {
        n /= 10;
        counter++;
    }
    return counter;
}

bool ArmstrongNumber(int n) {
    int sum = 0, n_initial = n, number_of_digits = NumberOfDigits(n);
    while (n > 0) {
        sum += pow (n % 10, number_of_digits);
        n /= 10;
    }
    bool b = (sum == n_initial);
    return b;
}

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа выводит все числа Армстронга, меньшие введённого пользователем числа.\n";
    std::cout << "Выполнил студент Арещенко Матвей, группа 453502.\n";
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
        int n;
        while (true) {
            std::cout << "Введите целое неотрицательное число, для которого нужно найти все числа Армстронга, которые меньше введённого числа.\n";
            n = CheckForIntegerInput();
            if (n < 0) {
                std::cout << "Неверный формат ввода.\n";
                continue;
            }
            break;
        }
        std::cout << "все числа Армстронга меньшие, чем " << n << ":\n";
        for (int i = 0; i < n; i++) {
            if (ArmstrongNumber(i)) {
                std::cout << i << '\n';
            }
        }
    }
    return 0;
}