#include <iostream>

long long MyAbs(long long x) {
    return (x >= 0 ? x : -x);
}

long long CheckForIntegerInput() {
    long long integer;
    while (!(std::cin >> integer) || (std::cin.get() != '\n'))  {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -9000000000000000000;
    }
    return integer;
}

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа вычисляет сумму 2^i * (-1)^i * a по всем i от 0 до n - 1.\n";
    std::cout << "Выполнил студент Арещенко Матвей, группа 453502.\n";
    while (true) {
        std::cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы.\n";
        long long action = CheckForIntegerInput();
        if (action != 1 && action != 2) {
            std::cout << "Неверный формат ввода.\n";
            continue;
        }
        if (action == 2) {
            break;
        }
        long long n;
        while (true) {
            std::cout << "Введите целое положительное число n.\n";
            n = CheckForIntegerInput();
            if (n <= 0) {
                std::cout << "Неверный формат ввода.\n";
                continue;
            }
            break;
        }
        long long a;
        while (true) {
            std::cout << "Введите целое число a.\n";
            a = CheckForIntegerInput();
            if (a == -9000000000000000000) {
                std::cout << "Неверный формат ввода.\n";
                continue;
            }
            break;
        }
        if (a == 0) {
            std::cout << "Ответ на задачу: " << 0 << ".\n";
            continue;
        }
        long long sum = 0, old_sum = 0, pow = 1, minus = 1;
        for (long long i = 0; i <= n - 1; i++) {
            old_sum = sum;
            sum += a * pow * minus;
            pow *= 2;
            minus *= -1;
            if ((MyAbs(sum) <= MyAbs(old_sum)) && (sum != -a)) {
                break;
            }
        }
        if ((MyAbs(sum) <= MyAbs(old_sum)) && (sum != -a)) {
            std::cout << "Переполнение.\n";
            continue;
        }
        std::cout << "Ответ на задачу: " << sum << ".\n";
    }
    return 0;
}