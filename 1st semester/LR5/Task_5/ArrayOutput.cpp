#include <iostream>

void ArrayOutput(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << *(arr + i) << ' ';
	}
	std::cout << '\n';
}