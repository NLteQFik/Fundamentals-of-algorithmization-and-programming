#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* left, char operation, Expression* right);
    ~BinaryOperation();
    double evaluate() override;

private:
    Expression* left;
    Expression* right;
    char operation;
};

#endif // BINARYOPERATION_H
