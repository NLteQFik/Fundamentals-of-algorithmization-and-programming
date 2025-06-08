#include "converter.h"

Converter::Converter() {}

long long Converter::Compute(long long n)
{
    if (n == 0) return 0;
    return GetPow(n) * (n % 10) + Compute(n / 10);
}

long long Converter::GetPow(long long n)
{
    if (n < 10) return 1;
    return 10 * GetPow(n / 10);
}
