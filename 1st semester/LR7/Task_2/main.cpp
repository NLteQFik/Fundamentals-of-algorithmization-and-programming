#include "Header.h"

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа осуществляет сложение двоичных чисел, заданных в естественной форме, с использованием дополнительного кода.\n";
    std::cout << "Выполнил Арещенко Матвей, группа 453502.\n";
    while (true) {
        int action = StartAndEnd();
        if (action == 2) {
            break;
        }

        std::string s1;
        std::string s2;
        StringInput(s1, 0); // O(n)
        StringInput(s2, 1); // O(n)

        int det = SignCheck(s1, s2);
        Addition(s1, s2); // O(n)

        if (det) {
            if (s1[0] == '-') {
                s1.erase(0, 1);
            }
            else {
                s1.insert(0, 1, '-');
            }
        }
        
        if (s1[0] == '-') {
            s1[0] = '1';
        }
        else {
            s1.insert(0, 1, '0');
        }
        std::cout << "Прямой код, полученный в результате сложения:\n";
        std::cout << s1 << '\n';
    }
}