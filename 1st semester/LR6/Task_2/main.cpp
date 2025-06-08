#include "Header.h"

TEST(Solve, minimal) {
    int size = 1;
    char *a = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        a[i] = 'v';
    }
    a[size - 1] = '\0';
    char substr[] = "ba";
    Solve(a, substr, size, 3, 1);
    EXPECT_EQ(a[0],'\0');
    free(a);
}

TEST(Solve, minimal_plus_1) {
    int size = 2;
    char *a = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        a[i] = 'v';
    }
    a[size - 1] = '\0';
    char substr[] = "b";
    Solve(a, substr, size, 2, 1);
    EXPECT_EQ(a[0],'b');
    EXPECT_EQ(a[1],'\0');
    free(a);
}

TEST(Solve, maximal_change) {
    int size = 1001;
    char *a = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        a[i] = 'v';
    }
    a[size - 1] = '\0';
    char *b = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        b[i] = 'l';
    }
    a[size - 1] = '\0';
    Solve(a, b, size, size, size - 1);
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(a[i],b[i]);
    }
    free(a);
    free(b);
}

TEST(Solve, maximal_not_change) {
    int size = 1001;
    char *a = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        a[i] = 'v';
    }
    a[size - 1] = '\0';
    char *b = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        b[i] = 'l';
    }
    a[size - 1] = '\0';
    Solve(a, b, size, size, size - 2);
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(a[i],'v');
    }
    free(a);
    free(b);
}

TEST(Solve, two_words) {
    int size = 10;
    char *a = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        a[i] = 'v';
    }
    a[3] = ' ';
    a[size - 1] = '\0';
    char b[] = "ne kto";
    Solve(a, b, size, 7, 3);
    char c[] = "ne kto vvvvv";
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(a[i],c[i]);
    }
    free(a);
}

TEST(Solve, four_words) {
    int size = 30;
    char *a = (char*)malloc(size * sizeof(char));
    char t[] = "Ya ne lyblu pisat gogle testi";
    for (int i = 0; i < 30; i++) {
        a[i] = t[i];
    }
    char b[] = "idiot ious";
    Solve(a, b, size, 11, 5);
    char c[] = "Ya ne idiot ious idiot ious idiot ious idiot ious";
    for (int i = 0; i < 50; i++) {
        EXPECT_EQ(a[i],c[i]);
    }
    free(a);
}

TEST(SymbolInput, letter_Y) {
    //У = D0A3;
    EXPECT_EQ(SymbolInput((char)0xD0, (char)0xA3), -45);
}

TEST(SymbolInput, letter_io) {
    //io = D191;
    EXPECT_EQ(SymbolInput((char)0xD1, (char)0x91), -72);
}

TEST(SymbolInput, letter_f) {
    //ф = D184;
    EXPECT_EQ(SymbolInput((char)0xD1, (char)0x84), -12);
}

TEST(BufferInput, zero_size) {
    char* s = (char*)malloc(1 * sizeof(char));
    EXPECT_EQ(BufferInput(s, 1), 1);
    free(s);
}

const int size = 80;

int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Программа заменяет в тексте слова заданной длины указанной подстрокой, длина которой может не совпадать с длиной слова.\n";
    std::cout << "Выполнил Арещенко Матвей, студент группы 453502, вариант 2.\n";
    while (true) {
        int action = StartAndEnd();
        if (action == 2) {
            break;
        }
        getchar();
        char *string = nullptr;
        std::cout << "Введите текст.\n";
        string = (char*)malloc(0);
        int string_size = StringInput(string, size);
        int length = IntegerInput();
        getchar();
        std::cout << "Введите подстроку.\n";
        char *sub_string = nullptr;
        sub_string = (char*)malloc(0);
        int sub_string_size = StringInput(sub_string, size);

        Solve(string, sub_string, string_size, sub_string_size, length);

        std::cout << "Полученный результат:\n";
        StringOutput(string, string_size);
        std::cout << '\n';

        free(string);
        string = nullptr;

        free(sub_string);
        sub_string = nullptr;

        
    }
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}