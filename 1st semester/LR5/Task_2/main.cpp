#include <iostream>
#include <Windows.h>

int main() {
	HINSTANCE load;
	load = LoadLibrary(L"MyDll.dll");

	typedef int (__stdcall *intin) ();
	intin StartAndEnd, IntegerInput;

	typedef void (__stdcall *ldarr) (long double*,int);
	ldarr LongDoubleArrayInput;

	typedef int(__stdcall* sol) (long double*, int);
	sol Solve;

	StartAndEnd = (intin)GetProcAddress(load, "StartAndEnd");
	IntegerInput = (intin)GetProcAddress(load, "IntegerInput");
	LongDoubleArrayInput = (ldarr)GetProcAddress(load, "LongDoubleArrayInput");
	Solve = (sol)GetProcAddress(load, "Solve");

	setlocale(LC_ALL, "russian");
	std::cout << "��������� ��� ��������� ����������� ������� X �� N �������� ���������, ��� ��� ���� ��������� ������� ����������� ������� -10 < x[i]^3 < 20.\n";
	std::cout << "�������� ������� �������� ������, ������ 453502, ������� 2.\n";

	while (true) {
		if (StartAndEnd() == 2) {
			break;
		}
		int k = IntegerInput();
		long double* a = new long double[k];
		LongDoubleArrayInput(a, k);
		if (Solve(a, k)) {
			std::cout << "������� �� �����������.\n";
		}
		else {
			std::cout << "������� �����������.\n";
		}
		delete[] a;
		a = nullptr;
	}

	FreeLibrary(load);
	return 0;
}