#include "../include/Four.h"
#include <cstring>   // Для memcpy, memset
#include <algorithm> // Для std::max
#include <stdexcept>

using namespace std;

// Конструкторы и деструктор

Four::Four()
    : digits(nullptr), size(0) {}

Four::Four(const size_t &n, unsigned char t)
    : size(n)
{
    if (t > 3)
        throw invalid_argument("Цифра должна быть от 0 до 3");

    digits = new unsigned char[size];
    for (size_t i = 0; i < size; ++i)
    {
        digits[i] = t;
    }

    normalize();
}

Four::Four(const std::initializer_list<unsigned char> &t)
    : size(t.size())
{
    digits = new unsigned char[size];
    size_t index = 0;
    try
    {
        for (auto it = t.begin(); it != t.end(); ++it, ++index)
        {
            if (*it < '0' || *it > '3')
                throw std::invalid_argument("Цифра должна быть от 0 до 3");

            digits[index] = *it - '0';
        }

        normalize();
    }
    catch (...)
    {
        delete[] digits;
        digits = nullptr;
        size = 0;
        throw;
    }
}


Four::Four(const std::string  &t)
{
    size = t.length();
    digits = new unsigned char[size];

    try
    {
        for (size_t i = 0; i < size; ++i)
        {
            char c = t[size - i - 1];
            if (c < '0' || c > '3')
                throw std::invalid_argument("Недопустимая цифра в строке");

            digits[i] = c - '0';
        }

        normalize();
    }
    catch (...)
    {
        delete[] digits;
        digits = nullptr;
        size = 0;
        throw;
    }
}

Four::Four(const Four &other)
    : digits(nullptr), size(0)
{
    copyFrom(other);
}

Four::Four(Four &&other) noexcept
    : digits(nullptr), size(0)
{
    moveFrom(std::move(other));
}

Four::~Four() noexcept
{
    release();
}

// Методы присваивания

void Four::assign(const Four &other)
{
    if (this != &other)
    {
        release();
        copyFrom(other);
    }
}

void Four::assignMove(Four &&other) noexcept
{
    if (this != &other)
    {
        release();
        moveFrom(std::move(other));
    }
}

// Арифметические методы

Four Four::add(const Four &other) const
{
    Four result = *this;
    result.addAssign(other);
    return result;
}

void Four::addAssign(const Four &other)
{
    if (this == &other) {
        Four temp(other);
        addDigits(temp);
    } else {
        addDigits(other);
    }
}

Four Four::subtract(const Four &other) const
{
    Four result = *this;
    result.subtractAssign(other);
    return result;
}

void Four::subtractAssign(const Four &other)
{
    if (this == &other) {
        Four temp(other);
        subtractDigits(temp);
    } else {
        subtractDigits(other);
    }
}

// Методы сравнения

bool Four::isEqual(const Four &other) const
{
    if (size != other.size)
        return false;
    for (size_t i = 0; i < size; ++i)
    {
        if (digits[i] != other.digits[i])
            return false;
    }
    return true;
}

bool Four::isNotEqual(const Four &other) const
{
    return !isEqual(other);
}

bool Four::isLessThan(const Four &other) const
{
    if (size != other.size)
        return size < other.size;
    for (size_t i = size; i > 0; --i)
    {
        if (digits[i - 1] != other.digits[i - 1])
            return digits[i - 1] < other.digits[i - 1];
    }
    return false;
}

bool Four::isLessThanOrEqual(const Four &other) const
{
    return isLessThan(other) || isEqual(other);
}

bool Four::isGreaterThan(const Four &other) const
{
    return !isLessThanOrEqual(other);
}

bool Four::isGreaterThanOrEqual(const Four &other) const
{
    return !isLessThan(other);
}

// Метод для вывода числа в виде строки

string Four::toString() const
{
    if (size == 0)
    {
        return "0";
    }
    string result;
    for (size_t i = size; i > 0; --i)
    {
        result += static_cast<char>('0' + digits[i - 1]);
    }
    return result;
}

// Вспомогательные методы

void Four::copyFrom(const Four &other)
{
    size = other.size;
    digits = new unsigned char[size];
    memcpy(digits, other.digits, size * sizeof(unsigned char));
}

void Four::moveFrom(Four &&other)
{
    digits = other.digits;
    size = other.size;
    other.digits = nullptr;
    other.size = 0;
}

void Four::release()
{
    delete[] digits;
    digits = nullptr;
    size = 0;
}

void Four::normalize()
{
    while (size > 0 && digits[size - 1] == 0)
    {
        --size;
    }
    if (size == 0)
    {
        delete[] digits;
        digits = new unsigned char[1];
        digits[0] = 0;
        size = 1;
    }
    else
    {
        unsigned char *newDigits = new unsigned char[size];
        memcpy(newDigits, digits, size * sizeof(unsigned char));
        delete[] digits;
        digits = newDigits;
    }
}

void Four::addDigits(const Four &other)
{
    size_t maxSize = std::max(size, other.size) + 1;
    unsigned char *resultDigits = new unsigned char[maxSize];
    memset(resultDigits, 0, maxSize * sizeof(unsigned char));

    size_t i = 0;
    unsigned char carry = 0;
    while (i < size || i < other.size)
    {
        unsigned char aDigit = (i < size) ? digits[i] : 0;
        unsigned char bDigit = (i < other.size) ? other.digits[i] : 0;
        unsigned char sum = aDigit + bDigit + carry;
        carry = sum / 4;
        resultDigits[i] = sum % 4;
        ++i;
    }
    if (carry > 0)
    {
        resultDigits[i] = carry;
        ++i;
    }
    delete[] digits;
    digits = resultDigits;
    size = i;
    normalize();
}

void Four::subtractDigits(const Four &other)
{
    if (isLessThan(other))
        throw std::underflow_error("Результат был бы отрицательным");

    size_t maxSize = size;
    unsigned char *resultDigits = new unsigned char[maxSize];
    memset(resultDigits, 0, maxSize * sizeof(unsigned char));

    size_t i = 0;
    unsigned char borrow = 0;
    while (i < size)
    {
        unsigned char aDigit = digits[i];
        unsigned char bDigit = (i < other.size) ? other.digits[i] : 0;
        unsigned char diff;
        if (aDigit < bDigit + borrow)
        {
            diff = static_cast<unsigned char>(aDigit + 4 - bDigit - borrow);
            borrow = 1;
        }
        else
        {
            diff = aDigit - bDigit - borrow;
            borrow = 0;
        }
        resultDigits[i] = diff;
        ++i;
    }

    if (borrow != 0)
    {
        delete[] resultDigits;
        throw std::underflow_error("Результат был бы отрицательным");
    }

    delete[] digits;
    digits = resultDigits;
    size = maxSize;
    normalize();
}