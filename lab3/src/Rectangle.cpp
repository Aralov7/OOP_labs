#include "../include/Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() : vertices(4) {}

Rectangle::Rectangle(const vector<pair<double, double>> &vertices) : vertices(vertices) {}

Rectangle::Rectangle(const Rectangle &other) : vertices(other.vertices) {}

Rectangle::Rectangle(Rectangle &&other) noexcept : vertices(move(other.vertices)) {}

Rectangle &Rectangle::operator=(const Rectangle &other)
{
    if (this != &other)
    {
        vertices = other.vertices;
    }
    return *this;
}

Rectangle &Rectangle::operator=(Rectangle &&other) noexcept
{
    if (this != &other)
    {
        vertices = move(other.vertices);
    }
    return *this;
}

bool Rectangle::operator==(const Rectangle &other) const
{
    return vertices == other.vertices;
}

pair<double, double> Rectangle::Center() const
{
    return PolygonCenter(vertices);
}

void Rectangle::Print(ostream &os) const
{
    os << "Rectangle vertices: ";
    for (const auto &vertex : vertices)
    {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Rectangle::Read(istream &is)
{
    vertices.resize(4);
    cout << "Введите 4 вершин (x y): ";
    for (auto &vertex : vertices)
    {
        is >> vertex.first >> vertex.second;
    }
}

Rectangle::operator double() const
{
    return PolygonArea(vertices);
}
