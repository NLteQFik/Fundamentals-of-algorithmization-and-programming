#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <limits>
#include "struct.h"

extern bool choice;
extern int n;
extern radio *tech;

int posIntegerInput();
long long posLongLongInput();
float posFloatInput();
double posDoubleInput();
std::string dateInput();
std::string nameInput();
std::string statInput();

void writeWorkFile();
void readWorkFile();
void rewriteFile(int, int);
void writeFinalFile();

void input();

void output();

void addition();

void removal();

void change();

void sort();
void sortOutput();

void option();

void view();