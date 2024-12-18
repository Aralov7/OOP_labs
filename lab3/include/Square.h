#pragma once
#include "Figure.h"
using namespace std;

class Square : public Figure
{
private:
    vector<pair<double, double>> vertices;

public:
    Square();
    Square(const vector<pair<double, double>> &vertices);
    Square(const Square &other);
    Square(Square &&other) noexcept;

    Square &operator=(const Square &other);
    Square &operator=(Square &&other) noexcept;
    bool operator==(const Square &other) const;

    pair<double, double> Center() const override;
    void Print(ostream &os) const override;
    void Read(istream &is) override;
    operator double() const override;
};