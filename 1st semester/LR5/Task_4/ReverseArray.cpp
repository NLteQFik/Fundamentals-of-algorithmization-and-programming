void ReverseArray(long double** arr, int n, int k) {
	long double x;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < k; j++) {
			x = *(*(arr + i) + j);
			*(*(arr + i) + j) = *(*(arr + n - 1 - i) + k - 1 - j);
			*(*(arr + n - 1 - i) + k - 1 - j) = x;
		}
	}
	if (n % 2) {
		int i = n / 2;
		for (int j = 0; j < k / 2; j++) {
			x = *(*(arr + i) + j);
			*(*(arr + i) + j) = *(*(arr + n - 1 - i) + k - 1 - j);
			*(*(arr + n - 1 - i) + k - 1 - j) = x;
		}
	}
}