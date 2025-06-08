#include <iostream>

int main() {
    long double a, b, c, Y;
    int N;
    std::cout << "Введите a, b, c и N через пробел: ";
    std::cin >> a >> b >> c >> N;
    switch (N)
    {
        case 2:
            Y = b*c - a*a;
            break;
        case 3:
            Y = a - b*c;
            break;
        case 7:
            Y = a*a + c;
            break;
        case 56:
            Y = b*c;
            break;
        default:
            Y = (a + b)*(a + b)*(a + b);
    }
    std::cout <<  Y << std::endl;
    return 0;
}