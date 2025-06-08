#include "Header.h"

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа заставляет рабов проверять бочки с вином.\n";
    std::cout << "Выполнил Арещенко Матвей, группа 453502.\n";
    while (true) {
        int cs = 1;
        int action = StartAndEnd(cs);
        if (action == 2) {
            cs++;
            action = StartAndEnd(cs);
            if (action == 1) {
                cs++;
                action = StartAndEnd(cs);
                if (action == 2) {
                    std::cout << "Вы совершили правильный поступок. Хорошего дня.";
                    break;
                }
            }
        }

        int number = IntegerInput();
        std::string s;
        Convert(s, number);
        std::cout << "Воспользуемся волшебной (троичной) системой счисления.\n";
        std::cout << "Пусть i-ый раб пьёт в 1-ый день из тех бочек, где (i-1)-ый разряд равен 1, а 2-ой день соотвественно 2.\n";
        std::cout << "Тогда к концу 2-ого дня мы сможем однозачно определеить (i-1)-ый разряд отравленной бочки\n";
        
        std::cout << "Хотите узнать номера бочек из которых будут пить рабы - введите 1, иначе 2\n";
        std::string q;
        std::cin >> q;
        if (q[0] == '1' && q.size() == 1) {
            std::cout << "Рабы не знают троичной системы. Тогда укажем им явно бочки, из которых они будут пить:\n\n";
            for (int i = 0; i < 5; i++) {
                Bochkas(i); // O(1) + O(2) + O(3) + O(4) + O(5) = O(1) 
                std::cout << '\n';
            }
        }
        else if (q[0] == '2' && q.size() == 1) {
        }
        else {
            std::cout << "Зачем проверять ввод? Идём дальше\n";
        }
        

        std::cout << "Переведём номер нашей бочки в трочиную систему:\n";
        std::cout << s << '\n';
        
        int old_number = number;
        int smert = 0;
        int count = 0;
        int arr[5]{};
        for (int i = 0; i < 5; i++) {
            if (number % 3 == 1) {
                arr[i] = 1;
                smert = 1;
                count++;
            }
            number /= 3;
        }

        if (smert) {
            std::cout << "Теперь к концу первого дня умерли рабы с номерами:\n";
            for (int i = 0; i < 5; i++) {
                if (arr[i]) {
                    std::cout << i + 1 << ' ';
                }
            }
        }
        else {
            std::cout << "Теперь к концу первого дня никто не умер.";
        }
        
        std::cout << "\nИ про номер бочки известно:\n";
        for (int i = 0; i < 5; i++) {
            if (arr[4 - i]) {
                std::cout << '1';
            }
            else {
                std::cout << '?';
            }
        }

        number = old_number;
        smert = 0;
        for (int i = 0; i < 5; i++) {
            if (number % 3 == 2) {
                arr[i] = 2;
                smert = 2;
                count++;
            }
            number /= 3;
        }

        if (smert) {
            std::cout << "\nЕщё один день проходит и к концу второго дня умирают рабы с номерами:\n";
            for (int i = 0; i < 5; i++) {
                if (arr[i] == 2) {
                    std::cout << i + 1 << ' ';
                }
            }
        }
        else {
            std::cout << "\nЕщё один день проходит и к концу второго дня никто не умирает.";
        }

        std::cout << "\nИ про номер бочки известно:\n";
        for (int i = 0; i < 5; i++) {
            if (arr[4 - i] == 1) {
                std::cout << '1';
            }
            else if (arr[4 - i] == 2) {
                std::cout << '2';
            }
            else {
                std::cout << '?';
            }
        }

        std::cout << "\nЗаменим вопросики на нули:\n";
        for (int i = 0; i < 5; i++) {
            if (arr[i] == 1) {
                s[4 - i] = '1';
            }
            else if (arr[i] == 2) {
                s[4 - i] = '2';
            }
            else {
                s[4 - i] = '0';
            }
        }
        std::cout << s;

        std::cout << "\nК сожалению, троичная система сложная, так что в десятичной системе наша бочка имеет номер:\n";
        number = Reconvert(s);
        std::cout << number;
        std::cout << "\nТакже умерло столько рабов: " << count;
        if (count == 5) {
            std::cout << "\nЭто наибольший результат\n";
        }
        else if (count == 1) {
            std::cout << "\nЭто наименьший результат\n";
        }
        else {
            std::cout << "\nНичего особенного в этом результате нет\n";
        }

    }
    return 0;
}