#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
private:
    vector<pair<double, double>> vertices;

public:
    Rectangle();
    Rectangle(const vector<pair<double, double>> &vertices);
    Rectangle(const Rectangle &other);
    Rectangle(Rectangle &&other) noexcept;

    Rectangle &operator=(const Rectangle &other);
    Rectangle &operator=(Rectangle &&other) noexcept;
    bool operator==(const Rectangle &other) const;

    pair<double, double> Center() const override;
    void Print(ostream &os) const override;
    void Read(istream &is) override;
    operator double() const override;
};