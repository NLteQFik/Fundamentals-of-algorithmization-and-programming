#include <iostream>

void ArrayOutput(long double** arr, int n, int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			std::cout << *(*(arr + i) + j) << ' ';
		}
		std::cout << '\n';
	}
}