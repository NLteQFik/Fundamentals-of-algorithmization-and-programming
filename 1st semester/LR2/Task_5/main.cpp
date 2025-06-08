#include <iostream>

int main() {
    long double X, Y;
    std::cout << "Введите числа X, Y через пробел: ";
    std::cin >> X >> Y;
    bool b = X > Y;
    std::cout << (b == 1 ? 'X' : 'Y') << " - наибольшее число\n";
    return 0;
}