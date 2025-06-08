void EvenDiagCreate(int** a, int size, int* evdiag) {
	int counter = 0;
	for (int i = 0; i < size; i++ ) {
		if (!(*(*(a + i) + i) % 2)) {
			*(evdiag + counter) = *(*(a + i) + i);
			counter++;
		}
	}
}