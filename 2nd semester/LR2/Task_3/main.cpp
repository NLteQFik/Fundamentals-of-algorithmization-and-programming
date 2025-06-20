#include <QCoreApplication>
#include <QTextStream>

#include <iostream>

#include "number.h"
#include "binaryoperation.h"

int main()
{
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << expr->evaluate() << '\n';
    delete expr;
    return 0;
}
