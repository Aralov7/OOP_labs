#include "../include/Figure.h"
#include <cmath>
#include <algorithm>

using namespace std;

double PolygonArea(const vector<pair<double, double>> &vertices)
{
    double area = 0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i)
    {
        double x1 = vertices[i].first;
        double y1 = vertices[i].second;
        double x2 = vertices[(i + 1) % n].first;
        double y2 = vertices[(i + 1) % n].second;
        area += (x1 * y2 - x2 * y1);
    }
    return abs(area) / 2.0;
}

pair<double, double> PolygonCenter(const vector<pair<double, double>> &vertices)
{
    double cx = 0;
    double cy = 0;
    double area = PolygonArea(vertices);
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i)
    {
        double xi = vertices[i].first;
        double yi = vertices[i].second;
        double xi1 = vertices[(i + 1) % n].first;
        double yi1 = vertices[(i + 1) % n].second;
        double cross = xi * yi1 - xi1 * yi;
        cx += (xi + xi1) * cross;
        cy += (yi + yi1) * cross;
    }
    double factor = 1 / (6 * area);
    cx *= factor;
    cy *= factor;
    return {cx, cy};
}

// Реализация класса Triangle

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

// Реализация класса Square

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

// Реализация класса Rectangle

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