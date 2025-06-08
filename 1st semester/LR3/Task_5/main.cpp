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

double CheckForRealInput() {
    double real;
    while (!(std::cin >> real) || (std::cin.get() != '\n'))  {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return real;
}

double function(double x) {
    return log(x) + 3 * tan(x) + sqrt(x);
}

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа приближённо ищет корень уравнения ln(x) + 3 * tan(x) + sqrt(x) = 0, где 2 <= x <= 4.\n";
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
            std::cout << "Введите число частей (положительное число), на которое надо разделить область поиска:\n";
            n = CheckForIntegerInput();
            if (n <= 0) {
                std::cout << "Неверный формат ввода.\n";
                continue;
            }
            break;
        }
        const int l = 2, r = 4;
        const int distance = r - l;
        double value = 0, min_value = function((double) l);
        double step = (double) distance / (double) n;
        double x = (double) l, root = (double) l;
        for (long double i = 0; i <= n; i++)
        {
            value = function(x);
            if (fabs(value) < fabs(min_value))
            {
                min_value = fabs(value);
                root = x;
            }
            x += step;
        }
        std::cout << "Приближенный корень найден и равен " << root << ".\n";
    }
    return 0;
}