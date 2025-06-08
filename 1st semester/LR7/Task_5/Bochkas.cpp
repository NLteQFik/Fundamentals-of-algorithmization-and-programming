#include "Header.h"

void Bochkas(int rab) {
    int divisor = 1;
    int count = 0;
    for (int i = 0; i < rab; i++) { // O(rab), но по факту O(1)
        divisor *= 3;
    }
    std::cout << "Раб под номером " << rab + 1 << " в первый день пьёт из бочек с номерами:\n";
    for (int i = 1; i <= 240; i++) {
        if ((i / divisor) % 3 == 1) {
            std::cout << i << ' ';
            count++;
            if (count == 9) {
                std::cout << "\n";
                count = 0;
            }
        }
    }
    if (!rab) {
        std::cout << '\n';
    }
    
    count = 0;
    std::cout << "\nВо второй:\n";
    for (int i = 1; i <= 240; i++) {
        if ((i / divisor) % 3 == 2) {
            std::cout << i << ' ';
            count++;
            if (count == 9) {
                std::cout << "\n";
                count = 0;
            }
        }
    }
    std::cout << '\n';
}