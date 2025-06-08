long double AverageMean(int* ptr, int size) {
	long double am = 0;
	long double s = (long double)size;
	for (int i = 0; i < size; i++) {
		am += (long double)*(ptr + i) / s;
	}
	return am;
}