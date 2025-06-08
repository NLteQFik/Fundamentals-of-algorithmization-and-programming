#include <iostream>

long double abs(long double x) {
    x = x >= 0 ? x : -x;
    return x;
}

int main() {
    int x, y;
    std::cout << "Введите два целых числа через пробел: ";
    std::cin >> x >> y;
    std::cout << x << " | " << y << std::endl;
    if (x < 0 || y < 0) {
        x = abs(x);
        y = abs(y);
        std::cout << x << " | " << y << std::endl;
    }
    while (x > 0 && y > 0) {
        if (x >= y)
            x %= y;
        else
            y %= x;
        std::cout << x << " | " << y << std::endl;
    }
    return 0;
}