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

char CheckForMatrixInput() {
    char number = 0;
    while (1) {
        char c = getchar();
        if (c == '*' || c == '.')
        {
            number = c;
            break;
        }
        else
        {
            while (c != '\n')
                c = getchar();
            return -1;
        }
    }
    return number;
}

int main() {
    printf("Сапёр.\n");
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
        int n;
        printf("Введите количество столбцов: \n");
        while (1) {
            n = CheckForIntegerInput();
            if (n == 0) {
                printf("Неверный формат ввода\n");
                continue;
            }
            break;
        }
        int m;
        printf("Введите количество строк: \n");
        while (1) {
            m = CheckForIntegerInput();
            if (m == 0) {
                printf("Неверный формат ввода\n");
                continue;
            }
            break;
        }
        char **a = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < m; i++) {
            a[i] = (char*)malloc(m * sizeof(char));
        }
        printf("Введите ");
        printf("%d", m);
        printf(" строк с ");
        printf("%d", n);
        printf(" элементами в каждой: \n");
        for (int i = 0; i < m; i++) {
            while (1) {
                int error = 0;
                for (int j = 0; j < n; j++) {
                    char mark = CheckForMatrixInput();
                    if (mark == -1) {
                        error = 1;
                        printf("Некоректный формат ввода.\n");
                        break;
                    }
                    else
                        a[i][j] = mark;
                }
                if (error == 0) {
                    char c = getchar();
                    if (c != '\n') {
                        printf("Некоректный формат ввода.\n");
                        while (c != '\n') {
                            c = getchar();
                        }
                    }
                    else { 
                        break;
                    }
                }
            }
        }
        int counter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '*') {
                    continue;
                }
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x < 0 || x > m - 1 || y < 0 || y > n - 1) {
                            continue;
                        }
                        if (x == i && y == j) {
                            continue;
                        }
                        if (a[x][y] == '*') {
                            counter++;
                        }
                    }
                }
                if (counter == 0) {
                    a[i][j] = ' ';
                }
                if (counter != 0) {
                    a[i][j] = counter;
                }
                counter = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '*' || a[i][j] == ' ') {
                    printf("%c", (char)a[i][j]);
                }
                else {
                    printf("%d", (int)a[i][j]); 
                }
            }
            printf("\n");
        }
    }
    return 0;
}