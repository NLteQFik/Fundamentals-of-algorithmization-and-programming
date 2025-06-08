#include "Header.h"

void StringInput(std::string& s, bool cs) {
    if (cs) {
        std::cout << "Введите второе двоичное число:\n";
    }
    else {
        std::cout << "Введите первое двоичное число:\n";
    }
    while (true) {
        std::cin >> s;
        
        bool b = 0;
        int i = 0;

        if (s[i] == '-') {
            if (s.size() == 1) {
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
        
        while (s[0] == '0' && s.size() > 1) { // O(n)
            s.erase(0, 1);
        }
        if (s[0] == '-') {
            while (s[1] == '0' && s.size() > 2) {
            s.erase(1, 1);
        }
        if (s[0] == '-' && s[1] == '0') {
            s.erase(0, 1);
        }
        }

        return;
    }
    
}