#pragma once
#include "figure.h"
#include "geometry_utils.h"
#include <vector>
#include <memory>

template <Scalar T>
class Rectangle : public Figure<T> {
private:
    std::vector<std::unique_ptr<Point<T>>> vertices;
public:
    Rectangle();
    Rectangle(const std::vector<Point<T>> &points);
    Rectangle(const Rectangle<T> &other);
    Rectangle(Rectangle<T> &&other) noexcept;

    Rectangle<T> &operator=(const Rectangle<T> &other);
    Rectangle<T> &operator=(Rectangle<T> &&other) noexcept;
    bool operator==(const Rectangle<T> &other) const;

    std::unique_ptr<Point<double>> Center() const override;
    void Print(std::ostream &os) const override;
    void Read(std::istream &is) override;
    operator double() const override;
};

template <Scalar T>
Rectangle<T>::Rectangle() {}

template <Scalar T>
Rectangle<T>::Rectangle(const std::vector<Point<T>> &points) {
    for (const auto &pt : points) {
        vertices.push_back(std::make_unique<Point<T>>(pt.x, pt.y));
    }
}

template <Scalar T>
Rectangle<T>::Rectangle(const Rectangle<T> &other) {
    for (const auto &pt : other.vertices) {
        vertices.push_back(std::make_unique<Point<T>>(pt->x, pt->y));
    }
}

template <Scalar T>
Rectangle<T>::Rectangle(Rectangle<T> &&other) noexcept : vertices(std::move(other.vertices)) {}

template <Scalar T>
Rectangle<T> &Rectangle<T>::operator=(const Rectangle<T> &other) {
    if (this != &other) {
        vertices.clear();
        for (const auto &pt : other.vertices) {
            vertices.push_back(std::make_unique<Point<T>>(pt->x, pt->y));
        }
    }
    return *this;
}

template <Scalar T>
Rectangle<T> &Rectangle<T>::operator=(Rectangle<T> &&other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

template <Scalar T>
bool Rectangle<T>::operator==(const Rectangle<T> &other) const {
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
std::unique_ptr<Point<double>> Rectangle<T>::Center() const {
    return PolygonCenter(vertices);
}

template <Scalar T>
void Rectangle<T>::Print(std::ostream &os) const {
    os << "Rectangle vertices: ";
    for (const auto &vertex : vertices) {
        os << *vertex << " ";
    }
    os << std::endl;
}

template <Scalar T>
void Rectangle<T>::Read(std::istream &is) {
    vertices.clear();
    std::cout << "Введите 4 вершин (x y): ";
    for (int i = 0; i < 4; ++i) {
        T x, y;
        is >> x >> y;
        vertices.push_back(std::make_unique<Point<T>>(x, y));
    }
}

template <Scalar T>
Rectangle<T>::operator double() const {
    return std::abs(PolygonArea(vertices));
}