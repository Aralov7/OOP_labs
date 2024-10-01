#include <gtest/gtest.h>
#include "../include/lab1.h"

// Тест для пустой строки
TEST(CountVowelsTest, EmptyString) {
    EXPECT_EQ(countVowels(""), 0);
}

// Тест для строки без гласных
TEST(CountVowelsTest, NoVowels) {
    EXPECT_EQ(countVowels("bcdfghjklmnpqrstvwxyz"), 0);
}

// Тест для строки с одной гласной
TEST(CountVowelsTest, OneVowel) {
    EXPECT_EQ(countVowels("a"), 1);
    EXPECT_EQ(countVowels("e"), 1);
    EXPECT_EQ(countVowels("i"), 1);
    EXPECT_EQ(countVowels("o"), 1);
    EXPECT_EQ(countVowels("u"), 1);
}

// Тест для строки с несколькими гласными
TEST(CountVowelsTest, MultipleVowels) {
    EXPECT_EQ(countVowels("hello world"), 3);
    EXPECT_EQ(countVowels("aeiou"), 5);
    EXPECT_EQ(countVowels("this is a test"), 4);
}

// Тест для строки с пробелами
TEST(CountVowelsTest, Spaces) {
    EXPECT_EQ(countVowels(" a e i o u "), 5);
}

// Тест для строки с повторяющимися гласными
TEST(CountVowelsTest, RepeatedVowels) {
    EXPECT_EQ(countVowels("aaeeiiouu"), 10);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}