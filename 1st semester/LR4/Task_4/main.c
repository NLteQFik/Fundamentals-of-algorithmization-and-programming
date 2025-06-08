#include <stdio.h>
#include <stdlib.h>

int maximum(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

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
        if (c < '0' || c > '9' || number >= 1,000,000,000)
        {
            printf("Неверный формат ввода\n");
            number = 0;
            while (c != '\n')
                c = getchar();
        }
    }
    return number;
}

int CheckForMatrixInput(int k, int t) {
    int number = 0;
    int end = 0;
    while (1) {
        char c = getchar();
        if (c == ' ') {
            if (t != k - 1) {
                break;
            }
            else {
                while (c != '\n')
                    c = getchar();
                return -1;
            }
        }
        if (c == '\n') {
            if (t == k - 1 && end)
                break;
            else
                return -1;
        }
        if (c >= '0' && c <= '9') {
            number = number * 10 + (c - '0');
            end = 1;
        }
        if (c < '0' || c > '9' || number >= 1e9) {
            while (c != '\n')
                c = getchar();
            return -1;
        }
    }
    return number;
}

int main() {
    printf("Программа определяет диагональ с наибольшей суммой чисел в трёхмерном динамическом массиве.\n");
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
        printf("Введите линейный размер куба k: ");
        while (1) {
            k = CheckForIntegerInput();
            if (k == 0) {
                continue;
            }
            break;
        }
        int*** arr = NULL;
        arr = (int***)malloc(k * sizeof(int**));
        for (int i = 0; i < k; i++) {
            arr[i] = (int**)malloc(k * sizeof(int*));
            for (int j = 0; j < k; j++) {
                arr[i][j] = (int*)malloc(k * sizeof(int));
            }
        }
        int number;
        printf("Введите k слоёв с k строками с k элементами в каждой: \n");
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                while (1) {
                    int error = 0;
                    for (int t = 0; t < k; t++) {
                        int element = CheckForMatrixInput(k, t);
                        if (element == -1) {
                            error = 1;
                            printf("Некоректный формат ввода.\n");
                            break;
                        }
                        else {
                            arr[i][j][t] = element;
                        }
                    }
                    if (error == 0) {
                        break;
                    }
                }
            }
        }
        int sumUL = 0, sumUR = 0, sumDL = 0, sumDR = 0;
        for (int i = 0; i < k; i++) {
            sumDL += arr[i][i][i];
        }
        for (int i = 0; i < k; i++) {
            sumUL += arr[k - 1 - i][i][i];
        }
        for (int i = 0; i < k; i++) {
            sumUR += arr[i][k - 1 -i][i];
        }
        for (int i = 0; i < k; i++) {
            sumDR += arr[i][i][k - 1 - i];
        }
        int max = maximum(maximum(sumUL, sumUR), maximum(sumDL, sumDR));
        if (max == sumDL) {
            printf("Диагональ с наибольшей суммой идёт из (0, 0, 0) в (k - 1, k - 1, k - 1) и сумма равна %d ", max);
            printf("\n");
        }
        if (max == sumUL) {
            printf("Диагональ с наибольшей суммой идёт из (k - 1, 0, 0) в (0, k - 1, k - 1) и сумма равна %d ", max);
            printf("\n");
        }
        if (max == sumUR) {
            printf("Диагональ с наибольшей суммой идёт из (0, k - 1, 0) в (k - 1, 0, k - 1) и сумма равна %d ", max);
            printf("\n");
        }
        if (max == sumDR) {
            printf("Диагональ с наибольшей суммой идёт из (0, 0, k - 1) в (k - 1, k - 1, 0) и сумма равна %d ", max);
            printf("\n");
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                free(arr[i][j]);
            }
            free(arr[i]);
        }
        free(arr);
        arr = NULL;
    }
    return 0;
}