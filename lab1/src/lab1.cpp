#include "../include/lab1.h"

// Функция для подсчета количества гласных букв в строке
int countVowels(const std::string& str) {
    int count = 0;
    for (char ch : str) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')    {
            count++;
        }
    }
    return count;
}

// Функция для чтения строки с использованием getchar
std::string readString() {
    std::string input;
    char ch;
    while ((ch = std::getchar()) != '\n') {
        input += ch;
    }
    return input;
}
