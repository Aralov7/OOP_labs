#include <iostream>
#include "include/lab1.h"

int main() {
    std::cout << "Введите строку: ";
    std::string input = readString();
    int vowelCount = countVowels(input);
    std::cout << "Количество гласных букв: " << vowelCount << std::endl;

    return 0;
}
