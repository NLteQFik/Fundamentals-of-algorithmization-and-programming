#pragma once
#include <iostream>
#include <gtest/gtest.h>

int StartAndEnd();
char SymbolInput(char, char);
int BufferInput(char*, int);
int StringInput(char*&, int);
int Solve(char*&, char*, int&, int, int);
char SymbolOutput(char);
int StringOutput(char*, int);
int IntegerInput();
