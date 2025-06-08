#include <iostream>
#include <cmath>

const double pi = 3.1415926535897932384626433832795;

int CheckForIntegerInput() {
    int integer;
    while (!(std::cin >> integer) || (std::cin.get() != '\n'))  {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return integer;
}

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа вычисляет значения функции y = sin(x) - cos(x) на отрезке [A,B] с помощью цикла for.\n";
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
        const int M = 20;
        const double A = 0, B = pi / 2;
        const double H = (B - A) / M;
        double X = A;
        for (int i = 0; i <= M; i++) {
            std::cout << "Значение функции y в точке X_" << i << " равно " <<  sin(X) - cos(X) <<".\n";
            X += H;
        }
    }
    return 0;
}