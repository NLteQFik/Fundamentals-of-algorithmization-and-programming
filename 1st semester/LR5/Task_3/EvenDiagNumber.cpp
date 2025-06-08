int EvenDiagNumber(int** a, int size) {
	int counter = 0;
	for (int i = 0; i < size; i++ ) {
		if (!(*(*(a + i) + i) % 2)) {
			counter++;
		}
	}
	return counter;
}