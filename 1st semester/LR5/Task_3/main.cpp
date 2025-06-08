#include <iostream>

int StartAndEnd();
int IntegerInput(int a);
void IntegerArrayInput(int** ptr, int n, int k);
long double Min(long double k, long double l);
int EvenDiagNumber(int**, int);
void EvenDiagCreate(int**, int, int*);

int main() {
	setlocale(LC_ALL, "russian");  
	std::cout << "��������� c����� ������������ ������ �� ���������, ������������� �� ������� ��������� ������� � ������� ������ �������� � ��������� ������������ ��������� ������� �������.\n";
	std::cout << "�������� ������� �������� ������, ������ 453502.\n";
	while (true) {
		if (StartAndEnd() == 2) {
			break;
		}
		int n, k;
		n = IntegerInput(1);
		k = IntegerInput(0);
		int** a = new int*[n];
		for (int i = 0; i < n; i++) {
			a[i] = new int[k];
		}
		IntegerArrayInput(a, n, k);
		long double min = Min(n, k);
		int number = EvenDiagNumber(a, min);
		if (!number) {
			std::cout << "�������� ������� �� ����������.\n";
			continue;
		}
		int* evdiag = new int[number];
		EvenDiagCreate(a, min, evdiag);
		long long mult = 1;
		std::cout << "������� ������.\n";
		for (int i = 0; i < number; i++) {
			std::cout << *(evdiag + i) << ' ';
			mult *= *(evdiag + i);
		}
		std::cout << '\n' << "������������ ��� ���������\n" << mult << '\n';
		for (int i = 0; i < n; i++) {
			delete[] a[i];
			a[i] = nullptr;
		}
		delete[] a;
		a = nullptr;
		delete[] evdiag;
		evdiag = nullptr;
	}
	return 0;
}