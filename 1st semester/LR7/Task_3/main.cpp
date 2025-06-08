#include "Header.h"

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа осуществляет сложение и вычитание чисел в заданной системе счисления.\n";
    std::cout << "Выполнил Арещенко Матвей, группа 453502.\n";
    while (true) {
        int action = StartAndEnd();
        if (action == 2) {
            break;
        }
        int base = IntegerInput();

        std::string s1;
        std::string s2;
        char sign;
        StringInput(s1, base, 0); // O(n)
        StringInput(s2, base, 1); // O(n)
        SignInput(sign);

        int det = SignCheck(s1, s2);
        if (sign == '+') {
            Addition(s1, s2, base); // O(n)
        }
        else {
            Subtraction(s1, s2, base); // O(n)
        }

        if (det) {
            if (s1[0] == '-') {
                s1.erase(0, 1);
            }
            else {
                s1.insert(0, 1, '-');
            }
        }
        
        std::cout << "Число, полученное в результате операции:\n";
        std::cout << s1 << '\n';
    }
}