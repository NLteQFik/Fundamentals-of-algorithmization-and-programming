#include <iostream>
#include <cmath>

int main() {
    int N;
    long double x, y, fx, z, a ,b;
    std::cout << "Введите z, a, b и номер функции N через пробел: ";
    std::cin >> z >> a >> b >> N;
    bool bl = z < 1;
    switch ((int) bl) {
        case 1:
            x = 2+z;
            std::cout << "x = 2 + z" << std::endl;
            break;
        default:
            x = sin(z)*sin(z);
            std::cout << "x = sin^2(z)" << std::endl;
    }
    switch (N) {
        case 1:
            fx = 2*x;
            std::cout << "fx = 2x" << std::endl;
            break;
        case 2:
            fx = x*x*x;
            std::cout << "fx = x^3" << std::endl;
            break;
        default:
            fx = x/3;
            std::cout << "fx = x/3" << std::endl;
    }
    y = (2*a*fx + b*cos(sqrt(fabs(x))))/(x*x+5);
    long double l = x;
    std::cout << "Значение y равно " << y << std::endl;
    return 0;
}