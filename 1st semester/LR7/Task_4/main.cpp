#include "Header.h"

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа проверяет, делится ли введенное пользователем число на заданное простое.\n";
    std::cout << "Заданные простые числа: 5, 47, 89.\n";
    std::cout << "Выполнил Арещенко Матвей, группа 453502.\n";
    while (true) {
        int action = StartAndEnd();
        if (action == 2) {
            break;
        }
    
        long long number = IntegerInput();

        DivisibilityCheck(number, 5); // O(log n)
        DivisibilityCheck(number, 47); // O(log n)
        DivisibilityCheck(number, 89); // O(log n)
    }
}