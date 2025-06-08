#pragma once
#include <iostream>
#include <gtest/gtest.h>

int StartAndEnd();
int NumberOfDigits(int);
int BufferInput(char*, int);
char SymbolInput(char, char);
int StringArrayInput(char**&, int, int*&);
int Fill(char*&, int, int, char, int);
int Solve(char*&, int&);
int ArraySolve(char**&, int, int*&);
char SymbolOutput(char);
int StringOutput(char*, int);
int ArrayStringOutput(char**, int, int*);