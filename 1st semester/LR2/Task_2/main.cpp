#include <iostream>

int main() {
    long double x, y, z;
    std::cout << "Введите числа (длины сторон треугольника) через пробел: ";
    std::cin >> x >> y >> z;
    if (x + y - z > 0 && y + z - x > 0 && z + x - y > 0)
        std::cout << "Треугольник с такими длинами сторон существует \n";
    else 
        std::cout << "Треугольника с такими длинами сторон не существует \n";
    return 0;
}