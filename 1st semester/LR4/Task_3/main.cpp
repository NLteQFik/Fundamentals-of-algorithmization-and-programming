#include <iostream>

int CheckForIntegerInput() {
    int integer;
    while (!(std::cin >> integer) || (std::cin.get() != '\n'))  {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return integer;
}

double CheckForRealInput() {
    double real;
    std::cin >> real;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -2000000000;
    }
    return real;
}

void CheckOfInputOfRealMassive(double* ptr, int size) {
    *(ptr + size - 1) = -2000000000;
    while (1) {
        for (int i = 0; i < size; i++) {
            *(ptr + i) = CheckForRealInput();
            if (*(ptr + i) == -2000000000) {
                std::cout << "Неверный формат ввода.\n";
                break;
            }
        }
        if (*(ptr + size - 1) == -2000000000) {
            continue;
        }
        if (std::cin.peek() != '\n') {
            continue;
        }
        break;
    }
}

void CheckOfInputOfReal2Massive(double** ptr, int size) {
    for (int i = 0; i < size; i++) {
        do {
            CheckOfInputOfRealMassive(*(ptr + i), size);
        } while (*(*ptr + size - 1 + i) == -2000000000);
    }
}

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа возводит квадратную вещественную матрицу А размером N в K-ю степень.\n";
    std::cout << "Выполнил студент Арещенко Матвей, группа 453502, вариант 2.\n";
    while (true) {
        std::cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы.\n";
        int action = CheckForIntegerInput();
        if (action != 1 && action != 2) {
            std::cout << "Неверный формат ввода.\n";
            continue;
        }
        if (action == 2) {
            break;
        }
        int N, K;
        while (true) {
            std::cout << "Введите размер N: \n";
            N = CheckForIntegerInput();
            if (N == -2000000000) {
                std::cout << "Неверный формат ввода.\n";
                continue;
            }
            break;
        }
        while (true) {
            std::cout << "Введите степень K: \n";
            K = CheckForIntegerInput();
            if (K == -2000000000) {
                std::cout << "Неверный формат ввода.\n";
                continue;
            }
            break;
        }
        std::cout << "Введите двумерный массив размером " << N << "x" << N << " чисел:\n";
        double** arr = new double*[N];
        for (int i = 0; i < N; i++) {
            arr[i] = new double[N];
        }
        CheckOfInputOfReal2Massive(arr, N);
        double** A = new double*[N];
        for (int i = 0; i < N; i++) {
            A[i] = new double[N];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = arr[i][j];
            }
        }
        double* B = new double[N];
        while (K > 1) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    B[j] = A[i][j];
                }
                for (int j = 0; j < N; j++) {
                    A[i][j] = 0;
                    for (int k = 0; k < N; k++) {
                        A[i][j] += B[k] * arr[k][j];
                    }
                }
            }
            K--;
        }
        std::cout << "Исходные данные:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << '\n';
        }
        std::cout << "Полученные данные:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << A[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
    return 0;
}