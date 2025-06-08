#include <iostream>

long double sqrt(long double x) {

    const long double pr = 1e-12;
    long double r, l;
    if (x >= 1) {
        l = 1;
        r = x;
    } else {
        l = x;
        r = 1;
    }
    while (r - l > pr) {
        long double mid = l/2 + r/2;
        if (mid*mid <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

long double cbrt(long double x) {
    const long double pr = 1e-12;
    long double r, l;
    if (x >= 0) {
        if (x>=1) {
        l = 1;
        r = x;
        } else {
        l = x;
        r = 1;
        }
    } else {
        if (x<=-1) {
        l = x;
        r = -1;
        } else {
        l = -1;
        r = x;
        }
    }
    while (r - l > pr) {
        long double mid = l/2 + r/2;
        if (mid*mid*mid <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

long double cbsl(long double p, long double q) {
    const long double pr = 1e-12;
        long double r, l;
        if (q >= 0) {
            if (1+p+q >= 0) {
            l = 1;
            r = sqrt(-p/3);
            } else {
            l = 0;
            r = 1;
            }
        } else {
            if (-1-p+q <= 0) {
            l = -sqrt(-p/3);
            r = -1;
            } else {
            l = -1;
            r = 0;
            }
        }
        while (r - l > pr) {
            long double mid = l/2 + r/2;
            if (mid*mid*mid + p*mid + q >= 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
}

int main (){
    long double p, q, Q;
    std::cout << "Введите p, q через пробел: ";
    std::cin >> p >> q;
    Q = (p/3)*(p/3)*(p/3)+(q/2)*(q/2);
    if (Q > 0) {
        long double alp, bet;
        alp = cbrt(-q/2+sqrt(Q));
        bet = cbrt(-q/2-sqrt(Q));
        std::cout << "Действительное решение: " << alp + bet << "\n";
    } else if (Q == 0) {
        long double r = cbrt(-q/2);
        std::cout << "Действительные решения: " << -r << " " << 2*r << "\n";
    } else {
        long double sl = cbsl(p, q);
        long double x1, x2;
        x1 = (-sl-sqrt(-4*p-3*sl*sl))/2;
        x2 = (-sl+sqrt(-4*p-3*sl*sl))/2;
        std::cout << "Действительные решения: " << x1 << " " << sl << " " << x2 << "\n"; 
    }
    return 0;
} 