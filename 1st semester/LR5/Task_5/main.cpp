#include <iostream>

int StartAndEnd();
int IntegerInput(int a);
void IntegerArrayInput(int** ptr, int n, int k);
void EvenColumnsOddElementsArray(int** arr, int n, int k, int* ptr);
int EvenColumnsOddElementsNumber(int** arr, int n, int k);
long double AverageMean(int* ptr, int size);
void ArrayOutput(int* arr, int n);

int main() {
	setlocale(LC_ALL, "russian");
	std::cout << "��������� ������ � ������� ������������ ������ �� ���������, ������������� � ������ �������� ������� ������� A � ��������� nxk � ������� �������� �������� � ��������� ������� �������������� ��������� ������������� �������.\n";
	std::cout << "�������� ������� �������� ������, ������ 453502.\n";
	while (true) {
		if (StartAndEnd() == 2) {
			break;
		}
		int n, k;
		n = IntegerInput(1);
		k = IntegerInput(0);
		int** a = new int* [n];
		for (int i = 0; i < n; i++) {
			a[i] = new int[k];
		}
		IntegerArrayInput(a, n, k);
		int l = EvenColumnsOddElementsNumber(a, n, k);
		if (l == 0) {
			std::cout << "������ ������������� ������� ����� ����.\n";
			continue;
		}
		int* b = new int[l];
		EvenColumnsOddElementsArray(a, n, k, b);
		std::cout << "������ ��������� ���������:\n";
		ArrayOutput(b, l);
		std::cout << "������� ��������������:\n";
		std::cout << AverageMean(b, l) << '\n';
		for (int i = 0; i < n; i++) {
			delete[] a[i];
			a[i] = nullptr;
		}
		delete[] a;
		a = nullptr;
		delete[] b;
		b = nullptr;
	}
	return 0;
}