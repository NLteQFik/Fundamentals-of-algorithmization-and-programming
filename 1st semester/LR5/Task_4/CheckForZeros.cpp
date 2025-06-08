#include <iostream>

int CheckForZeros(long double** arr, int n, int k) {
	bool b = 0;
	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (*(*(arr + i) + j) == 0) {
				if (b == 0) {
					std::cout << "Нули на позициях:\n";
				}
				std::cout << "(" << i << "," << j << ")\n";
				b = 1;
				counter++;
			}
 		}
	}
	return counter;
}