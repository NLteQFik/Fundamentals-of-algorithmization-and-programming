#include <iostream>

extern "C" int __declspec(dllexport) __stdcall Solve(long double* a, int size) {
	if (size > 1) {
		if (Solve(a, size / 2)) {
			return 1;
		};
		if (Solve(a + (size / 2), size - size / 2)) {
			return 1;
		};
		return 0;
	}
	else {
		long double x = *a;
		if (x > -10 && x < 20) {
			if (x * x * x > -10 && x * x * x < 20) {
				//std::cout << "YES\n";
				return 0;
			}
			else {
				//std::cout << "NO\n";
				return 1;
			}
		}
		else {
			//std::cout << "NO\n";
			return 1;
		}
	}
}