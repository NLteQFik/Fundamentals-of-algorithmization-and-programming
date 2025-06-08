#include "..\Task_1\HeaderTask1.h"

int main() {
	setlocale(LC_ALL, "russian");
	std::cout << "��������� ������ ��������� a_i * x + b_j = 0 ��� ���� i, j = 0, 1, ..., 7 , ��� a_i � b_j - �������� ������������ ��������.\n";
	std::cout << "�������� ������� �������� ������, ������ 453502, ������� 1.\n";
	while (true) {
		if (StartAndEnd() == 2) {
			break;
		}
		int k = IntegerInput();
		long double* a = new long double[k];
		long double* b = new long double[k];
		LongDoubleArrayInput(a, k, 1);
		LongDoubleArrayInput(b, k, 0);
		Solve(a, 8, b, 8);
		delete[] a;
		delete[] b;
		a = nullptr;
		b = nullptr;
	}
	return 0;
}