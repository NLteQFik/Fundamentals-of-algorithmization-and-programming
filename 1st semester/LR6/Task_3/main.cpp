#include "Header.h"

const int size = 101;

TEST(Solve, minimal) {
    int size = 1;
    char *string = (char*)malloc(size * sizeof(char));
    string[0] = 'a';
    Solve(string, size);
    EXPECT_EQ(string[0],'a');
    free(string);
}

TEST(Solve, maximal) {
    int size = 101;
    char *a = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        a[i] = 'v';
    }
    a[size - 1] = '\0';
    char b[] = "255118100";
    Solve(a, size);
    for (int i = 0; i < 9; i++) {
        EXPECT_EQ(a[i],b[i]);
    }
    free(a);
}

TEST(Solve, consequance_letters) {
    int size = 13;
    char *a = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        a[i] = (char)i + 'a';
    }
    a[size - 1] = '\0';
    char b[] = "abcdefghijkl";
    Solve(a, size);
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(a[i],b[i]);
    }
    free(a);
}

TEST(Solve, triple_three) {
    int size = 19;
    char *a = (char*)malloc(size * sizeof(char));
    char t[] = "aa bbbbbbbbbb cccc";
    for (int i = 0; i < size; i++) {
        a[i] = t[i];
    }
    char c[] = "2550972 25509810 2550994";
    Solve(a, size);
    for (int i = 0; i < 24; i++) {
        EXPECT_EQ(a[i],c[i]);
    }
    free(a);
}

TEST(Solve, random_words) {
    int size = 52;
    char *a = (char*)malloc(size * sizeof(char));
    char t[] = "Ya ne lyblu dooble and eee... ya ne soshol s yyyyma";
    for (int i = 0; i < 52; i++) {
        a[i] = t[i];
    }
    char c[] = "Ya ne lyblu d2551112ble and 25510132550463 ya ne soshol s 2551214ma";
    Solve(a, size);
    for (int i = 0; i < 68; i++) {
        EXPECT_EQ(a[i],c[i]);
    }
    free(a);
}

TEST(SymbolInput, letter_Y) {
    //У = D0A3;
    EXPECT_EQ(SymbolInput((char)0xD0, (char)0xA3), -45);
}

TEST(Fill, 44u) {
    char* string = (char*)malloc(8 * sizeof(char));
    Fill(string, 0, 8, 'u', 44);
    char b[] = "25511744";
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(string[i], b[i]); 
    }
    free(string);
}

TEST(Fill, 64ia) {
    char* string = (char*)malloc(8 * sizeof(char));
    Fill(string, 0, 8, (char)-1, 64);
    char b[] = "25525564";
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(string[i], b[i]); 
    }
    free(string);
}

TEST(NumberOfDigits, 10567) {
    EXPECT_EQ(NumberOfDigits(10567), 5);
}

TEST(BufferInput, zero_size) {
    char* s = (char*)malloc(1 * sizeof(char));
    EXPECT_EQ(BufferInput(s, 1), 0);
    free(s);
}

TEST(NumberOfDigitsd, zero) {
    EXPECT_EQ(NumberOfDigits(0), 1);
}

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа обрабатывает массив строк. Если в строке встречена последовательность одинаковых символов, заменяет их кодом 255, за которым следует код этого символа и количество одинаковых символов.\n";
    std::cout << "Выполнил Арещенко Матвей, студент группы 453502, вариант 2.\n";
    while (true) {
        int action = StartAndEnd();
        if (action == 2) {
            break;
        }
        getchar();
        std::cout << "Введите массив строк. Чтобы завершить ввод, оставьте строку без символов и переёдите на следующую с помощью Enter.\n";
        char **string_array = nullptr;
        string_array = (char**)malloc(0);
        int *array_sizes = nullptr;
        array_sizes = (int*)malloc(0);
        int string_array_size = StringArrayInput(string_array, size, array_sizes);
        ArraySolve(string_array, string_array_size, array_sizes);
        std::cout << "В итоге имеем:\n";
        ArrayStringOutput(string_array, string_array_size, array_sizes);

        for (int i = 0; i < string_array_size; i++) {
            free(string_array[i]);
            string_array[i] = nullptr;
        } 
        free(string_array);
        string_array = nullptr;

        free(array_sizes);
        array_sizes = nullptr;
    }

    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}