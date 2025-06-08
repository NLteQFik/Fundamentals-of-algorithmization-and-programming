#include "binaryoperation.h"


BinaryOperation::BinaryOperation(Expression *left, char operation, Expression *right)
{
    this->left = left;
    this->operation = operation;
    this->right = right;
}

BinaryOperation::~BinaryOperation()
{
    delete left;
    delete right;
}

double BinaryOperation::evaluate()
{
    switch (operation) {
    case '+':
        return left->evaluate() + right->evaluate();
        break;
    case '-':
        return left->evaluate() - right->evaluate();
        break;
    case '*':
        return left->evaluate() * right->evaluate();
        break;
    case '/':
        return left->evaluate() / right->evaluate();
        break;
    default:
        return 0.0;
        break;
    }
}
