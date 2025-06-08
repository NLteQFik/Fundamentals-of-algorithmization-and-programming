#include "Header.h"

void StringInput(std::string& s, int base, bool cs) {
    if (cs) {
        std::cout << "Введите второе число:\n";
    }
    else {
        std::cout << "Введите первое число:\n";
    }
    while (true) {
        std::cin >> s;
        int mx;
        if (base > 10) {
            mx = 64 + (base - 10);
        }
        else {
            mx = 47 + base;
        }

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
            s[i] = toupper(s[i]);
            if (((48 <= (int)s[i]) && ((int)s[i] <= 57) && ((int)s[i] <= mx)) || ((65 <= (int)s[i]) && ((int)s[i] <= mx))) {
                continue;
            }
            b = 1;
            break;
        }

        if (b) {
            std::cout << "Неверный формат ввода!" << '\n';
            continue;
        }
        
        while (s[0] == '0' && s.size() > 1) {
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