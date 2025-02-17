#pragma once
#include "figure.h"
#include "geometry_utils.h"
#include <vector>
#include <memory>

template <Scalar T>
class Square : public Figure<T> {
private:
    std::vector<std::unique_ptr<Point<T>>> vertices;
public:
    Square();
    Square(const std::vector<Point<T>> &points);
    Square(const Square<T> &other);
    Square(Square<T> &&other) noexcept;

    Square<T> &operator=(const Square<T> &other);
    Square<T> &operator=(Square<T> &&other) noexcept;
    bool operator==(const Square<T> &other) const;

    std::unique_ptr<Point<double>> Center() const override;
    void Print(std::ostream &os) const override;
    void Read(std::istream &is) override;
    operator double() const override;
};


template <Scalar T>
Square<T>::Square() {}

template <Scalar T>
Square<T>::Square(const std::vector<Point<T>> &points) {
    for (const auto &pt : points) {
        vertices.push_back(std::make_unique<Point<T>>(pt.x, pt.y));
    }
}

template <Scalar T>
Square<T>::Square(const Square<T> &other) {
    for (const auto &pt : other.vertices) {
        vertices.push_back(std::make_unique<Point<T>>(pt->x, pt->y));
    }
}

template <Scalar T>
Square<T>::Square(Square<T> &&other) noexcept : vertices(std::move(other.vertices)) {}

template <Scalar T>
Square<T> &Square<T>::operator=(const Square<T> &other) {
    if (this != &other) {
        vertices.clear();
        for (const auto &pt : other.vertices) {
            vertices.push_back(std::make_unique<Point<T>>(pt->x, pt->y));
        }
    }
    return *this;
}

template <Scalar T>
Square<T> &Square<T>::operator=(Square<T> &&other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

template <Scalar T>
bool Square<T>::operator==(const Square<T> &other) const {
    if (vertices.size() != other.vertices.size()) {
        return false;
    }
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i]->x != other.vertices[i]->x || vertices[i]->y != other.vertices[i]->y) {
            return false;
        }
    }
    return true;
}

template <Scalar T>
std::unique_ptr<Point<double>> Square<T>::Center() const {
    return PolygonCenter(vertices);
}

template <Scalar T>
void Square<T>::Print(std::ostream &os) const {
    os << "Square vertices: ";
    for (const auto &vertex : vertices) {
        os << *vertex << " ";
    }
    os << std::endl;
}

template <Scalar T>
void Square<T>::Read(std::istream &is) {
    vertices.clear();
    std::cout << "Введите 4 вершины (x y): ";
    for (int i = 0; i < 4; ++i) {
        T x, y;
        is >> x >> y;
        vertices.push_back(std::make_unique<Point<T>>(x, y));
    }
}

template <Scalar T>
Square<T>::operator double() const {
    return PolygonArea(vertices);
}