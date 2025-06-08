#include "converter.h"

Converter::Converter()
{

}

QString Converter::IntegerToBin(int n)
{
    if (n == 1) return "1";
    if (n == 0) return "0";
    return IntegerToBin(n / 2) + ((n - n / 2 * 2) ? "1" : "0");

}

QString Converter::FractionalToBin(double n, int counter = 0)
{
    counter++;
    if (n < 1e-6) return "";
    if (counter > round_number) return "";
    return (2 * n >= 1 ? "1" + FractionalToBin(2 * n - 1, counter) : "0" + FractionalToBin(2 * n, counter));

}

QString Converter::GetBinary()
{
    return this->binary;
}

void Converter::Compute(double decimal, int round)
{
    round_number = round;
    int integer_part = qFloor(decimal);
    double fractional_part = decimal - integer_part;
    this->binary = IntegerToBin(integer_part);
    this->binary += "." + FractionalToBin(fractional_part, 0);
    if (binary.back() == '.') binary.chop(1);
}
