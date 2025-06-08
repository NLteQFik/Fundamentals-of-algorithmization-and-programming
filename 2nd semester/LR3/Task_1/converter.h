#ifndef CONVERTER_H
#define CONVERTER_H

#include <QtMath>
#include <QString>
#include <QDebug>

class Converter
{
private:
    QString binary;
    int round_number;
protected:
    QString IntegerToBin(int);
    QString FractionalToBin(double, int);
public:
    Converter();
    QString GetBinary();
    void Compute(double, int);
};

#endif // CONVERTER_H
