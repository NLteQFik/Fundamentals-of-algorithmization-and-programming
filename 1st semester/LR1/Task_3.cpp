#include <iostream>
#include <cmath>
#include <gtest/gtest.h>

TEST(Sintest, sintest)
{
    ASSERT_EQ(sin(6), -0.27941549819892586);
}

int main() {
double touble, start, end, step;
std::cout << "Введите начальное значение x: ";
std::cin >> start; // Задаем исходное значение переменной
std::cout << "Введите конечное значение x: ";
std::cin >> end; // Задаем конечно значение переменной
std::cout << "Введите шаг: ";
std::cin >> step; // Задаем шаг, с которым с которым будет изменяться
// аргумент
for (double x = start; x <= end; x += step) {
double y = sin(x); // функция y = sin(x)
std::cout << x << " | " << y << std::endl; // Выводим значения
// функции для каждого аргумента (x | y)
}
testing::InitGoogleTest();
RUN_ALL_TESTS();
return 0;
}
