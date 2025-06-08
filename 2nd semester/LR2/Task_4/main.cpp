#include <QCoreApplication>
#include <QTextStream>

#include <iostream>

#include "number.h"
#include "binaryoperation.h"

bool check_equals(Expression const* left, Expression const* right)
{
    if (*(int**)left == *(int**)right)
        return true;
    return false;
}

int main()
{
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    //Expression* some = new BinaryOperation(new Number(10), '*', new Number(12));
    std::cout << expr->evaluate() << '\n';
    delete expr;
    //delete some;
    return 0;
}
