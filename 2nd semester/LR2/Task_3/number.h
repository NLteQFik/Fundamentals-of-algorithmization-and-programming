#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
public:
    Number(double value);
    double evaluate() override;

private:
    double number;
};

#endif // NUMBER_H
