#pragma once
#include <iostream>

extern "C" int __declspec(dllexport) __stdcall IntegerInput();
extern "C" int __declspec(dllexport) __stdcall LongDoubleArrayInput(long double* ptr, int size);
extern "C" int __declspec(dllexport) __stdcall StartAndEnd();
extern "C" void __declspec(dllexport) __stdcall Solve(long double* a, int size);