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
    std::cout << "Программа вычисляет сумму (ai-bi)^2 для i от 1 до 30 c помощью цикла while.\n";
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
        int sum = 0;
        int i = 1;
        while (i <= 30) {
            int ai =  (i % 2 == 0 ? i / 2 : i);
            int bi =  (i % 2 == 0 ? i * i * i : i * i);
            sum += (ai - bi) * (ai - bi);
            ++i;
        }
        std::cout << "Ответ на задачу: " << sum << ".\n";
    }
    return 0;
}