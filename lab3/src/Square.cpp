#include "../include/Square.h"
#include <iostream>
using namespace std;

Square::Square() : vertices(4) {}

Square::Square(const vector<pair<double, double>> &vertices) : vertices(vertices) {}

Square::Square(const Square &other) : vertices(other.vertices) {}

Square::Square(Square &&other) noexcept : vertices(move(other.vertices)) {}

Square &Square::operator=(const Square &other)
{
    if (this != &other)
    {
        vertices = other.vertices;
    }
    return *this;
}

Square &Square::operator=(Square &&other) noexcept
{
    if (this != &other)
    {
        vertices = move(other.vertices);
    }
    return *this;
}

bool Square::operator==(const Square &other) const
{
    return vertices == other.vertices;
}

pair<double, double> Square::Center() const
{
    return PolygonCenter(vertices);
}

void Square::Print(ostream &os) const
{
    os << "Square vertices: ";
    for (const auto &vertex : vertices)
    {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Square::Read(istream &is)
{
    vertices.resize(4);
    cout << "Введите 4 вершины (x y): ";
    for (auto &vertex : vertices)
    {
        is >> vertex.first >> vertex.second;
    }
}

Square::operator double() const
{
    return PolygonArea(vertices);
}
