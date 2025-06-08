#include <iostream>

int StartAndEnd();
int IntegerInput(int a);
void LongDoubleArrayInput(long double** ptr, int n, int k);
int CheckForZeros(long double** ptr, int n, int k);
void ReverseArray(long double** ptr, int n, int k);
void ArrayOutput(long double** arr, int n, int k);

int main() {
	setlocale(LC_ALL, "russian");
	std::cout << "��������� ���������� ������� ������� ��������� ������� A �������� nxm � �� ���������� � ������������ �������� ������� � �������� �������.\n";
	std::cout << "�������� ������� �������� ������, ������ 453502.\n";
	while (true) {
		if (StartAndEnd() == 2) {
			break;
		}
		int n, k;
		n = IntegerInput(1);
		k = IntegerInput(0);
		long double** a = new long double* [n];
		for (int i = 0; i < n; i++) {
			a[i] = new long double[k];
		}
		LongDoubleArrayInput(a, n, k);
		std::cout << "���������� �����:\n" << CheckForZeros(a, n, k) << '\n';
		ReverseArray(a, n, k);
		std::cout << "�������������� ������:\n";
		ArrayOutput(a, n, k);
		for (int i = 0; i < n; i++) {
			delete[] a[i];
			a[i] = nullptr;
		}
		delete[] a;
		a = nullptr;
	}
	return 0;
}