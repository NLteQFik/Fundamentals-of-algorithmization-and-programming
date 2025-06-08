#include "Header.h"

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа переводит из дополнительного кода в обратный.\n";
    std::cout << "Выполнил Арещенко Матвей, группа 453502.\n";
    while (true) {
        int action = StartAndEnd();
        if (action == 2) {
            break;
        }
    
        std::string s;
        StringInput(s); // O(n)
        Convert(s); // O(n)
        std::cout << "Обратный код:\n";
        std::cout << s << '\n';
    }
    return 0;
}