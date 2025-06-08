#include <iostream>
#include <cmath>

const double precision = 1.0e-5;
const double pi = 3.1415926535897932384626433832795;
const double e = 2.71828182845904523536028747135266;

int CheckForIntegerInput() {
    int integer;
    while (!(std::cin >> integer) || (std::cin.get() != '\n'))  {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return integer;
}

double CheckForRealInput() {
    double real;
    while (!(std::cin >> real) || (std::cin.get() != '\n'))  {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return 0;
    }
    return real;
}

double MyAbs(double x) {
    x = (x >= 0 ? x : -x);
    return x;
}

double MyCos(double x) {
    double sum = 0, member = 1;
    int k = 1;
    while (MyAbs(member) > precision) {
        sum += member;
        member *= -x / (2*k-1) * x / (2*k);
        k++;
    }
    return sum;
}

double MySin(double x) {
    double member = x;
    double sum = 0;
    int k = 1;
    while (MyAbs(member) > precision) {
        sum += member;
        member *= -x / (2 * k) * x / (2 * k + 1);
        k++;
    }
    return sum;
}

double argument(double x) {
    double pow = 1;
        while (x > 2 * pi) {
        while (4 * pi * pow <= x) {
            pow *= 2;
        }
        x -= pow * 2 * pi;
        pow = 1;
    }
    return x;
}

double ln(double x) {
    int counter = 0;
    while (x > 1) {
        x = x / e;
        counter++; 
    }
    double member = x - 1;
    double sum = 0;
    int n = 1;
    while (MyAbs(member) > precision) {
        sum += member;
        member *= -(x - 1) * n / (n + 1);
        n++;
    }
    sum += (double) counter;
    return sum;
}

void GoodFunction() {
    const int number = 1;
    const double pr = 1e-3;
    int counter = 0;
    double init = 1e20;
    double x = init;
    while (init <= 1e300) {
        for (int i = 3; i <= 30; i++) {
            while(x <= 1e300) {
                if (MyAbs(cos(argument(x)) - cos(x)) < pr && MyAbs(sin(argument(x)) - sin(x)) < pr && MyAbs(ln(x) - log(x)) < pr && x >= 1e200) {
                    std::cout << counter + 1 << ")\n";
                    std::cout << "my cos: " << MyCos(argument(x)) <<".\n";
                    std::cout << "cos: " << cos(x) <<".\n";
                    std::cout << "my sin: " << MySin(argument(x))  <<".\n";
                    std::cout << "sin: " << sin(x) <<".\n";
                    std::cout << "my log: " << ln(x) <<".\n";
                    std::cout << "log: " << log(x) <<".\n";
                    std::cout << "Число: " << x << ".\n\n";
                    counter++;
                }
                if (counter >= number) {
                    break;
                }
                x *= i;
            }
            if (counter >= number) {
                break;
            }
            x = init;
        }
        if (counter >= number) {
            break;
        }
        init *= 10;
    }
}

double min(double a, double b, double c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа вычисляет минимальное из sinx, cosx, ln|x|.\n";
    std::cout << "Выполнил студент Арещенко Матвей, группа 453502.\n";
    while (true) {
        std::cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы.\n";
        int action = CheckForIntegerInput();
        if (action != 1 && action != 2) {
            std::cout << "Неверный формат ввода.\n";
            continue;
        }
        if (action == 2) {
            break;
        }
        double x = 0;
        while (true) {
            std::cout << "Введите x.\n";
            x = CheckForRealInput();
            if (x == 0) {
                std::cout << "Неверный формат ввода.\n";
                continue;
            }
            if (MyAbs(x) > 1e15) {
                std::cout << "Для такого большого числа программа не гарантирует точности полученного результа, так как имеются значительные погрешности при округлении чисел.\n";
            }
            double minimum = 0;
            if (x >= e) {
                x = argument(x);
                minimum = min(cos(x), sin(x), 1);
            }
            if (x <= -e) {
                x = -argument(-x);
                minimum = min(cos(x), sin(x), 1);
            }
            if (MyAbs(x) <= 1){
                minimum = ln(MyAbs(x));
            }
            if (MyAbs(x) > 1 && MyAbs(x) < e) {
                minimum = min(cos(x), sin(x), ln(MyAbs(x) / e) + 1);
            }
            std::cout << "Минимальное значение: " << minimum <<".\n";
            std::cout << "my cos: " << MyCos(argument(x)) <<".\n";
            std::cout << "my sin: " << MySin(argument(x))  <<".\n";
            std::cout << "my log: " << ln(x) <<".\n";
            std::cout << "cos: " << cos(x) <<".\n";
            std::cout << "sin: " << sin(x) <<".\n";
            std::cout << "log: " << log(x) <<".\n\n";
            GoodFunction();
            break;
        }
    }
    return 0;
}