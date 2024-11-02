#include <string>
#include <initializer_list>

class Four
{
public:
    // Конструкторы
    Four();
    Four(const size_t &n, unsigned char t = 0);
    Four(const std::initializer_list<unsigned char> &t);
    Four(const std::string &t);
    Four(const Four &other);
    Four(Four &&other) noexcept;
    virtual ~Four() noexcept;

    // Методы присваивания
    void assign(const Four &other);
    void assignMove(Four &&other) noexcept;

    // Арифметические методы
    Four add(const Four &other) const;
    void addAssign(const Four &other);

    Four subtract(const Four &other) const;
    void subtractAssign(const Four &other);

    // Методы сравнения
    bool isEqual(const Four &other) const;
    bool isNotEqual(const Four &other) const;
    bool isLessThan(const Four &other) const;
    bool isLessThanOrEqual(const Four &other) const;
    bool isGreaterThan(const Four &other) const;
    bool isGreaterThanOrEqual(const Four &other) const;

    // Метод для вывода числа в виде строки
    std::string toString() const;

private:
    unsigned char *digits; // Динамический массив цифр
    size_t size;           // Количество цифр

    void copyFrom(const Four &other);
    void moveFrom(Four &&other);
    void release();

    void normalize(); // Удаление незначащих нулей

    // Вспомогательные методы
    void addDigits(const Four &other);
    void subtractDigits(const Four &other);
};