#include "Header.h"

void StringInput(std::string& s) {
    std::cout << "Введите дополнительный код:\n";
    while (true) {
        std::cin >> s;

        bool b = 0;
        int i = 0;

        if (s[i] == '-') {
            if (s.size() > 0) {
                std::cout << "Неверный формат ввода!" << '\n';
                continue;
            }
            i++;
        }
        for (; i < s.size(); i++) { // O(n)
            if (s[i] == '0' || s[i] == '1') {
                continue;
            }
            b = 1;
            break;
        }

        if (b) {
            std::cout << "Неверный формат ввода!" << '\n';
            continue;
        }

        return;
    }
    
}