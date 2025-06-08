#include "functions.h"

bool choice;
int n;
product *goods;

int main() {
    choice = 1;
    setlocale(LC_ALL, "russian");
    std::cout << "Выполнил Арещенко Матвей, группа 453502.\n";

    std::cout << "Вы хотите загрузить сохранённую информацию?\n";

    int type = 0;
    while (true) {
        std::cout << "1. Загрузить предыдущее сохранение\n";
        std::cout << "2. Создать новое\n";
        

        type = posIntegerInput();

        if (type == 1) {
            readFile();
            break;
        }
        if (type == 2){
            break;
        }
        std::cout << "Неверный формат ввода!\n";
    } 

    bool b;

    while (true) {
        std::cout << "\nМеню выбора функций:\n";
        std::cout << "1. Ввод динамического одномерного массива структур:\n";
        std::cout << "2. Просмотр содержимого динамического массива структур:\n";
        std::cout << "3. Добавление в существующий массив структур новых структур\n";
        std::cout << "4. Поиск и вывод на экран структур с заданным значением элемента\n";
        std::cout << "5. Удаление структур с заданным значением элемента\n";
        std::cout << "6. Изменение структур с заданным значением элемента\n";
        std::cout << "7. Упорядочение массива структур по одному из полей\n";
        std::cout << "8. Выбор шестого поля структуры\n";
        std::cout << "9. Вид структуры\n";
        std::cout << "10. Выход из программы\n";
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
                search();
                break;
            case 5:
                removal();
                break;
            case 6:
                change();
                break;
            case 7:
                sortOutput();
                break;
            case 8:
                option();
                break;
            case 9:
                view();
                break;
            case 10:
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

    free(goods);
    return 0;
}