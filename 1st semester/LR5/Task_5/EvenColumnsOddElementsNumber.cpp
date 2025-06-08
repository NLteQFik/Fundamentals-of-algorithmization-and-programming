int EvenColumnsOddElementsNumber(int** arr, int n, int k) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < k; j += 2) {
			if (*(*(arr + i) + j) % 2) {
				counter++;
			}
		}
	}
	return counter;
}