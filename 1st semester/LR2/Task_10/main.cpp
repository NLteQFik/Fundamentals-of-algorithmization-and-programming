#include <iostream>

int main() {
    long double x1, y1, r, x2, y2, R;
    bool a, b, c, d;
    std::cout << "Введите x1, y1, r, x2, y2, R: ";
    std::cin >> x1 >> y1 >> r >> x2 >> y2 >> R;
    a = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) > R*R + r*r + 2*R*r;
    b = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) > R*R + r*r - 2*R*r;
    c = R > r;
    d = r > R;
    if (a == 1)
        std::cout << "Ни одно условие не выполнено\n";
    else if (b == 1)
        std::cout << "Фигуры пересекаются\n";
    else if (c == 1)
        std::cout << "Да\n";
    else if (d == 1)
        std::cout << "Да, но справедливо обратное для двух фигур\n";
    else 
        std::cout << "Да, но круги совпадают\n";
    return 0;
}