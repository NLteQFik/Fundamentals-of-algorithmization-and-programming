#include <iostream>

int main() {
    long long int X, Y, X1, Y1;
    long double A, B, C, K, A1, B1, C1;
    std::cout << "Введите числа X, Y, A, B, C, K через пробел: ";
    std::cin >> X >> Y >> A >> B >> C >> K;
    X1 = X > Y ? X : 0;
    Y1 = Y > X ? Y : 0;
    A1 = A > B && A > C ? A - K : A;
    B1 = B > C && B > A ? B - K : B;
    C1 = C > A && C > B ? C - K : C;
    X = X1;
    Y = Y1;
    A = A1;
    B = B1;
    C = C1;
    std::cout << X << " " << Y << " " << A << " " << B << " " << C << std::endl;
    return 0;
}