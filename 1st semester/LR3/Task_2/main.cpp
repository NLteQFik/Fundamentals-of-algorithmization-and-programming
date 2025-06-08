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

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа вычисляет сумму ряда (1/2^n)+(1/3^n) с помощью цикла do while.\n";
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
        const double eps = 1.0e-3;
        double sum = 0;
        double r2 = 2, r3 = 3;
        double dn = 0;
        do {
            dn = (r2 + r3) / (r2 * r3);
            r2 *= 2;
            r3 *= 3;
            sum += dn;
        } while (dn >= eps);
        std::cout << "Ответ на задачу: " << sum << ".\n";
    }
    return 0;
}