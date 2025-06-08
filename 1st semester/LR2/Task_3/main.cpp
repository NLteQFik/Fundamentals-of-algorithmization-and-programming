#include <iostream>

int main() {
    long double n, b1, sum;
    n = 15;
    std::cout << "Введите первый член геометрической прогрессии b1: ";
    std::cin >> b1;
    sum = b1 * (1 + 1/n);
    std::cout << "Сумма всех членов убывающей геометрической прогрессии равна: " << sum << std::endl; 
    return 0;
}