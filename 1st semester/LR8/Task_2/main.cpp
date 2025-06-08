#include "functions.h"

bool choice;
int n;
radio *tech;

int main() {
    choice = 1;
    setlocale(LC_ALL, "russian");
    std::cout << "Выполнил Арещенко Матвей, группа 453502.\n";

    int type = 0;

    bool b;

    while (true) {
        std::cout << "\nМеню выбора функций:\n";
        std::cout << "1. Ввод динамического одномерного массива структур:\n";
        std::cout << "2. Просмотр содержимого динамического массива структур:\n";
        std::cout << "3. Добавление в существующий массив структур новых структур\n";
        std::cout << "4. Удаление структур с заданным значением элемента\n";
        std::cout << "5. Изменение структур с заданным значением элемента\n";
        std::cout << "6. Упорядочение массива структур по одному из полей\n";
        std::cout << "7. Выбор шестого поля структуры\n";
        std::cout << "8. Вид структуры\n";
        std::cout << "9. Выход из программы\n";
        std::cout << "Выберите функцию:\n";
        
        b = 1;
        type = posIntegerInput();
        std::cout << '\n';

        switch (type) {
            case 1:
                input();
                break;
            case 2:
                output();
                break;
            case 3:
                addition();
                break;
            case 4:
                removal();
                break;
            case 5:
                change();
                break;
            case 6:
                sortOutput();
                break;
            case 7:
                option();
                break;
            case 8:
                view();
                break;
            case 9:
                b = 0;
                break;
            default:
                std::cout << "Неверный формат ввода!\n";
        }
        if (b) {
            continue;
        }
        break;
    }

    writeFinalFile();

    free(tech);
    return 0;
}