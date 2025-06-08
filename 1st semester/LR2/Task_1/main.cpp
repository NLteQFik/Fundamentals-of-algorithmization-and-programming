#include <iostream>

int main() {
    long double x, t, a, b;
    std::cout << "Введите значение x: ";
    std::cin >> x;
    t = x*x;
    a = 69*t+8;
    b = (23*t+32)*x;
    std::cout << "Значение первого выражения: " << a+b << std::endl;
    std::cout << "Значение второго выражения: " << a-b << std::endl;
    return 0;
}