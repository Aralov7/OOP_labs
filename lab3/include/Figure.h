#pragma once 
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Figure
{
public:
    virtual ~Figure() = default;
    virtual pair<double, double> Center() const = 0;
    virtual void Print(ostream &os) const = 0;
    virtual void Read(istream &is) = 0;
    virtual operator double() const = 0;

    friend ostream &operator<<(ostream &os, const Figure &figure)
    {
        figure.Print(os);
        return os;
    }

    friend istream &operator>>(istream &is, Figure &figure)
    {
        figure.Read(is);
        return is;
    }
};

class Triangle : public Figure
{
private:
    vector<pair<double, double>> vertices;

public:
    Triangle();
    Triangle(const vector<pair<double, double>> &vertices);
    Triangle(const Triangle &other);
    Triangle(Triangle &&other) noexcept;

    Triangle &operator=(const Triangle &other);
    Triangle &operator=(Triangle &&other) noexcept;
    bool operator==(const Triangle &other) const;

    pair<double, double> Center() const override;
    void Print(ostream &os) const override;
    void Read(istream &is) override;
    operator double() const override;
};

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
