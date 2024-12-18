#include "../include/Triangle.h"
#include <iostream>
using namespace std;


Triangle::Triangle() : vertices(3) {}

Triangle::Triangle(const vector<pair<double, double>> &vertices) : vertices(vertices) {}

Triangle::Triangle(const Triangle &other) : vertices(other.vertices) {}

Triangle::Triangle(Triangle &&other) noexcept : vertices(move(other.vertices)) {}

Triangle &Triangle::operator=(const Triangle &other)
{
    if (this != &other)
    {
        vertices = other.vertices;
    }
    return *this;
}

Triangle &Triangle::operator=(Triangle &&other) noexcept
{
    if (this != &other)
    {
        vertices = move(other.vertices);
    }
    return *this;
}

bool Triangle::operator==(const Triangle &other) const
{
    return vertices == other.vertices;
}

pair<double, double> Triangle::Center() const
{
    return PolygonCenter(vertices);
}

void Triangle::Print(ostream &os) const
{
    os << "Triangle vertices: ";
    for (const auto &vertex : vertices)
    {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Triangle::Read(istream &is)
{
    vertices.resize(3);
    cout << "Введите 3 вершины (x y): ";
    for (auto &vertex : vertices)
    {
        is >> vertex.first >> vertex.second;
    }
}

Triangle::operator double() const
{
    return PolygonArea(vertices);
}