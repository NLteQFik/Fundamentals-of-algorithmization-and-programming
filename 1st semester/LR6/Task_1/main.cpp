#include "Header.h"

TEST(FindShortAndType, min) {
    char a[1]{'\0'};
    int solve = FindShortAndType(a, 1);
    EXPECT_EQ(solve, 0);
}

TEST(FindShortAndType, max1) {
    char a[81];
    for (int i = 0; i < 80; i++) {
        a[i] = '1';
    }
    a[80] = '\0';
    int solve = FindShortAndType(a, 81);
    EXPECT_EQ(solve, 80);
}

TEST(FindShortAndType, max0) {
    char a[81];
    for (int i = 0; i < 80; i++) {
        a[i] = '0';
    }
    a[80] = '\0';
    int solve = FindShortAndType(a, 81);
    EXPECT_EQ(solve, -80);
}

TEST(FindShortAndType, max10) {
    char a[81];
    for (int i = 0; i < 40; i++) {
        a[i] = '1';
    }
    for (int i = 40; i < 80; i++) {
        a[i] = '0';
    }
    a[80] = '\0';
    int solve = FindShortAndType(a, 81);
    EXPECT_EQ(solve, 40);
}

TEST(FindShortAndType, max01) {
    char a[81];
    for (int i = 0; i < 40; i++) {
        a[i] = '0';
    }
    for (int i = 40; i < 80; i++) {
        a[i] = '1';
    }
    a[80] = '\0';
    int solve = FindShortAndType(a, 81);
    EXPECT_EQ(solve, -40);
}

TEST(FindShortAndType, random_test) {
    char a[21] = "11110000011110000110";
    int solve = FindShortAndType(a, 21); 
    EXPECT_EQ(solve, -1);
}

TEST(ZeroesAndOnesCheck, not10) {
    EXPECT_EQ(ZeroesAndOnesCheck('a'), 1);
}

TEST(Min, b_is_bigger) {
    EXPECT_EQ(Min(-5, 6, 1), -5);
}

TEST(Min, a_is_bigger_and_b_postive) {
    EXPECT_EQ(Min(-7, 6, 1), 6);
} 

TEST(Min, a_is_bigger_and_b_negative) {
    EXPECT_EQ(Min(-7, 6, 0), -6);
} 

const int size = 81;

int main() {
    setlocale(LC_ALL, "russian");
    char buffer[size];
    int length;
    int solve;
    std::cout << "Программа в строке, состоящей из групп нулей и единиц, находит и выводит на экран самую короткую группу\n";
    std::cout << "Выполнил Арещенко Матвей, студент группы 453502, вариант 2\n";
    while (true) {
        int action = StartAndEnd();
        if (action == 2) {
            break;
        }
        getchar();
        std::cout << "Введите строку не более, чем из 80 символов:\n";
        while (!(length = ZeroesAndOnesInput(buffer, size))) {
            std::cout << "Неверный формат ввода!\n";
        }
        char *str = new char[length];
        for (int i = 0; i < length; i++) {
            str[i] = buffer[i];
        }
        std::cout << "Введённая строка:\n";
        std::cout << str << '\n';
        solve = FindShortAndType(str,length);
        std::cout << "Самая короткая группа:\n";
        if (solve < 0) {
            for (int i = 0; i < -solve; i++) {
                std::cout << 0;
            }
        }
        else {
            for (int i = 0; i < solve; i++) {
                std::cout << 1;
            }
        }
        std::cout << '\n';
        delete[] str;
        str = nullptr;
    }
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}