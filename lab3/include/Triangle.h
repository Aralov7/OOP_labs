#pragma once
#include "Figure.h"

class Triangle : public Figure
{
private:
    std::vector<std::pair<double, double>> vertices;

public:
    Triangle();
    Triangle(const std::vector<std::pair<double, double>> &vertices);
    Triangle(const Triangle &other);
    Triangle(Triangle &&other) noexcept;

    Triangle &operator=(const Triangle &other);
    Triangle &operator=(Triangle &&other) noexcept;
    bool operator==(const Triangle &other) const;

    std::pair<double, double> Center() const override;
    void Print(std::ostream &os) const override;
    void Read(std::istream &is) override;
    operator double() const override;
};