#include <iostream>

void Solve(long double* a, int size_a, long double* b, int size_b) {
	long double x;
	std::cout << "������� ��� ���� ��������� a,b c ��������� (i,j) ����� ��������������:\n";
	for (int i = 0; i < size_a; i++) {
		for (int j = 0; j < size_b; j++) {
			if (*(a + i)) {
				x = -*(b + j) / *(a + i);
			}
			else {
				x = 0;
			}
			std::cout << "(" << i << "," << j << "): " << x << "\n";
		}
	}
}