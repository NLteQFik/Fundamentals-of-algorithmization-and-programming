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

long double arcsin(long double x) {
    const long double pr = 1e-12;
    int n = 0;
    long double seqm = x;
    long double sum = 0;
    while (seqm > pr || seqm < -pr) {
        sum += seqm;
        seqm *= (x*x*(2*n+1)/(2*n+2)*(2*n+1)/(2*n+3));
        n++;
    }
    return sum;
}

long double abs(long double x) {
    x = x >= 0 ? x : -x;
    return x;
}

int main() {
    const long double pi = 3.1415926535897932384626433832795;
    long double x1, y1, x2, y2, x3, y3;
    std::cout << "Введите x1, y1, x2, y2, x3, y3 через пробел: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    long double S;
    S = abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3)/2;
    
    long double a, b, c;
    a = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    b = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
    c = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    std::cout << "Длины сторон треугольника: " << a << " " << b << " " << c << "\n";
    
    long double ha, hb, hc;
    ha = 2*S/a;
    hb = 2*S/b;
    hc = 2*S/c;
    std::cout << "Длины высот треугольника: " << ha << " " << hb << " " << hc << "\n";
    
    long double ma, mb, mc;
    ma = sqrt(2*c*c + 2*b*b - a*a)/2;
    mb = sqrt(2*a*a + 2*c*c - b*b)/2;
    mc = sqrt(2*b*b + 2*a*a - c*c)/2;
    std::cout << "Длины медиан треугольника: " << ma << " " << mb << " " << mc << "\n";
    
    long double la, lb, lc;
    la = sqrt(c*b)*sqrt(a+b+c)*sqrt(b+c-a)/(b+c);
    lb = sqrt(c*a)*sqrt(a+b+c)*sqrt(a+c-b)/(a+c);
    lc = sqrt(a*b)*sqrt(a+b+c)*sqrt(b+a-c)/(b+a);
    std::cout << "Длины биссектрис треугольника: " << la << " " << lb << " " << lc << "\n";

    long double R, r;
    R = a*b/(4*S)*c;
    r = 2*S/(a+b+c);

    long double alp, bet, gam, rada, radb, radc;
    rada = a*a <= b*b + c*c ? arcsin(a/(2*R)) : pi - arcsin(a/(2*R));
    radb = b*b <= a*a + c*c ? arcsin(b/(2*R)) : pi - arcsin(b/(2*R));
    radc = c*c <= b*b + a*a ? arcsin(c/(2*R)) : pi - arcsin(c/(2*R));
    alp = rada/pi*180;
    bet = radb/pi*180;
    gam = radc/pi*180;
    std::cout << "Градусная и радианная мера углов треугольника: " << alp << " " << bet << " " << gam << " " << rada << " " << radb << " " << radc << "\n";

    std::cout << "Радиусы вписанной и описанной окружностей треугольника: " << r << " " << R << "\n";

    long double Arinc, Arcir, Linc, Lcir;
    Arinc = pi*r*r;
    Arcir = pi*R*R;
    Linc = 2*pi*r;
    Lcir = 2*pi*R;
    std::cout << "Площадь и длина вписанной окружности треугольника: " << Arinc << " " << Linc << "\n";
    std::cout << "Площадь и длина описанной окружности треугольника: " << Arcir << " " << Lcir << "\n";

    long double S1, S2, p, cosa;
    p = (a+b+c)/2;
    S1 = sqrt(p)*sqrt(p-a)*sqrt(p-b)*sqrt(p-c);
    cosa = (b*b+c*c-a*a)/(2*b*c);
    S2 = b*c/2*sqrt(1 - cosa*cosa);
    std::cout << "Площадь (3 способа) и периметр треугольника: " << S << " " << S1 << " " << S2 << " " << 2*p << "\n";
    return 0;
} 



