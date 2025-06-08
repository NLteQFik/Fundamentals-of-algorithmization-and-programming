#include "ackermannfunction.h"

AckermannFunction::AckermannFunction() {}

long long AckermannFunction::Compute(long long m, long long n)
{
    if (m == 0) return n + 1;
    if (m > 0 && n == 0) return Compute(m - 1, 1);
    return Compute(m - 1, Compute(m, n - 1));
}
