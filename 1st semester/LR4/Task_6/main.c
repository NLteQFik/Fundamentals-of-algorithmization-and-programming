#include <stdio.h>
#include <stdlib.h>

int CheckForIntegerInput() {
    int number = 0;
    while (1)
    {
        char c = getchar();
        if (c == '\n') {
            break;
        }
        if (c >= '0' && c <= '9')
            number = number * 10 + (c - '0');
        if (c < '0' || c > '9' || number >= 1000000000) {
            printf("Неверный формат ввода\n");
            number = 0;
            while (c != '\n')
                c = getchar();
        }
    }
    return number;
}

void ArrayOfZeros(int** ptr, int size, int number, int l, int r) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(ptr + l + i) + r + j) = number;
        }
    }
}

void SiameseMethod(int** ptr, int size, int number, int l, int r) {
    ArrayOfZeros(ptr, size, number, l, r);
    int i = 0, j = size / 2;
    for (int n = 0; n < size * size; n++) {
        *(*(ptr + l + i) + r + j) += n + 1;
        i--;
        j++;
        if (i == -1) {
            i = size - 1;
        }
        if (j == size) {
            j = 0;
        }
        if (*(*(ptr + i + l) +  r + j) != number) {
            i += 2;
            j--;
        }
        if (i == size) {
            i = 0;
        }
        if (i == size + 1) {
            i = 1;
        }
        if (j == -1) {
            j = size - 1;
        }
    }
}

void StracheyMethod(int** ptr, int size) {
    int half = size / 2;
    SiameseMethod(ptr, half, 0, 0 ,0);
    SiameseMethod(ptr, half, half * half, half, half);
    SiameseMethod(ptr, half, 2 * half * half, 0, half);
    SiameseMethod(ptr, half, 3 * half * half, half, 0);
    int k = half / 2;
    int save;
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < half; i++) {
            save = *(*(ptr + i) + j);
            *(*(ptr + i) + j) = *(*(ptr + i + half) + j);
            *(*(ptr + i + half) + j) = save;
        }
    }
    for (int j = size - 1; j > size - k; j--) {
        for (int i = 0; i < half; i++) {
            save = *(*(ptr + i) + j);
            *(*(ptr + i) + j) = *(*(ptr + i + half) + j);
            *(*(ptr + i + half) + j) = save;
        }
    }
    save = *(*(ptr + k) + 0);
    *(*(ptr + k) + 0) = *(*(ptr + k + half) + 0);
    *(*(ptr + k + half) + 0) = save;
    save = *(*(ptr + k) + k);
    *(*(ptr + k) + k) = *(*(ptr + k + half) + k);
    *(*(ptr + k + half) + k) = save;
}

void RightArray(int** ptr, int size) {
    int number = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(ptr + i) + j) = number;
            number++;
        }
    }
}

void DoubleEvenMethod(int** ptr, int size) {
    RightArray(ptr, size);
    for (int i = 0; i < size; i++) {
        if (i % 4 == 0 || i % 4 == 3) {
            for (int j = 0; j < size; j++) {
                if (j % 4 == 1 || j % 4 == 2) {
                    *(*(ptr + i) + j) = size * size + 1 - *(*(ptr + i) + j);
                }
            }
        } 
        if (i % 4 == 1 || i % 4 == 2) {
            for (int j = 0; j < size; j++) {
                if (j % 4 == 0 || j % 4 == 3) {
                    *(*(ptr + i) + j) = size * size + 1 - *(*(ptr + i) + j);
                }
            }
        } 
    }
}

int main() {
    printf("Программа выводит магичиский квадрат со стороной k.\n");
    printf("Выполнил студент Арещенко Матвей, группа 453502\n");
    while (1) {
        int action;
        printf("Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы.\n");
        action = CheckForIntegerInput();
        if (action != 1 && action != 2) {
            continue;
        }
        if (action == 2) {
            break;
        }
        int k;
        printf("Введите сторону магического квадрата: ");
        while (1) {
            k = CheckForIntegerInput();
            if (k == 0) {
                continue;
            }
            break;
        }
        if (k == 2) {
            printf("NO\n");
            continue;
        }
        int** square = NULL;
        square = (int**)malloc(k * sizeof(int*));
        for (int i = 0; i < k; i++) {
            square[i] = (int*)malloc(k * sizeof(int));
        }
        if (k % 2 == 1) {
            SiameseMethod(square, k, 0, 0, 0);
        }
        if (k % 4 == 2) {
            StracheyMethod(square, k);
        }
        if (k % 4 == 0) {
            DoubleEvenMethod(square, k);
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                printf("%d", square[i][j]);
                printf(" ");
            }
            printf("\n");
        }
        for (int i = 0; i < k; i++) {
            free(square[i]);
        }
        free(square);
        square = NULL;
    }
    return 0;
}