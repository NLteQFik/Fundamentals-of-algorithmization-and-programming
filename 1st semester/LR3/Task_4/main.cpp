#include <iostream>
#include <cmath>

int CheckForIntegerInput() {
    int integer;
    if (!(std::cin >> integer) || (std::cin.get() != '\n'))  {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return integer;
}

double CheckForRealInput() {
    double real;
    if (!(std::cin >> real) || (std::cin.get() != '\n'))  {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return real;
}

double Y(double x) {
    return ((exp(x) + exp(-x)) / 2);
}

double S(double x, int a) {
    double value = 0;
    double member = 1; 
    for (int i = 1; i <= a; i++) {
        value += member;
        member *= x / (2 * i - 1) * x / (2 * i);
    }
    return value;
}

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа сравнивает значение функции (e^x + e^(-x)) / 2, вычисленное с помощью разложения в ряд, со значением, вычисленным с помощью стандартных функций.\n";
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
        int n;
        while (true) {
            std::cout << "Введите количество членов ряда (целое неотрицательное число):\n";
            n = CheckForIntegerInput();
            if (n < 0) {
                std::cout << "Неверный формат ввода.\n";
                continue;
            }
            break;
        }
        int k;
        while (true) {
            std::cout << "Введите количество чисел, от которых нужно посчитать функцию (целое неотрицательное число):\n";
            k = CheckForIntegerInput();
            if (k < 0) {
                std::cout << "Неверный формат ввода.\n";
                continue;
            }
            break;
        }
        for (int i = 1; i <= k; i++) {
            double x;
            while (true) {
                std::cout << "Введите число, от которого нужно вычислить значение функции (действительное число от 0.1 до 1):\n";
                x = CheckForRealInput();
                if (x < 0.1 || x > 1) {
                    std::cout << "Неверный формат ввода.\n";
                    continue;
                }
                break;
            }
            std::cout << "Значение функции, полученное с помощью ряда равно: " << S(x, n) << ".\n";
            std::cout << "Значение функции, полученное с помощью стандартных функций равно: " << Y(x) << ".\n";
        }
    }
    return 0;
}