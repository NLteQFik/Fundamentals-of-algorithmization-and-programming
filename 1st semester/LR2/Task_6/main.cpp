#include <iostream>
#include <cmath>

int main() {
    long double x, p, K, Y, A, B, C, D;
    std::cout << "Введите числа x, p, K, D, C через пробел: ";
    std::cin >> x >> p >> K >> D >> C;
    A = x + sin(p);
    B = exp(K);
    Y = 1 + K*K/(2*A*B) - B + D*C;
    std::cout << "Y равно: " << Y << std::endl;
    return 0;
}