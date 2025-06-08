#include <iostream>

int StartAndEnd();
int IntegerInput(int a);
void LongDoubleArrayInput(long double** ptr, int n, int k);
int CheckForZeros(long double** ptr, int n, int k);
void ReverseArray(long double** ptr, int n, int k);
void ArrayOutput(long double** arr, int n, int k);

int main() {
	setlocale(LC_ALL, "russian");
	std::cout << "Программа определяет индексы нулевых элементов матрицы A размером nxm и их количество и переставляет элементы массива в обратном порядке.\n";
	std::cout << "Выполнил студент Арещенко Матвей, группа 453502.\n";
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
		std::cout << "Количество нулей:\n" << CheckForZeros(a, n, k) << '\n';
		ReverseArray(a, n, k);
		std::cout << "Переставленный массив:\n";
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