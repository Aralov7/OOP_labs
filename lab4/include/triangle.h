#pragma once
#include "figure.h"
#include "geometry_utils.h"
#include <vector>
#include <memory>

template <Scalar T>
class Triangle : public Figure<T> {
private:
    std::vector<std::unique_ptr<Point<T>>> vertices;
public:
    Triangle();
    Triangle(const std::vector<Point<T>> &points);
    Triangle(const Triangle<T> &other);
    Triangle(Triangle<T> &&other) noexcept;

    Triangle<T> &operator=(const Triangle<T> &other);
    Triangle<T> &operator=(Triangle<T> &&other) noexcept;
    bool operator==(const Triangle<T> &other) const;

    std::unique_ptr<Point<double>> Center() const override;
    void Print(std::ostream &os) const override;
    void Read(std::istream &is) override;
    operator double() const override;
};


template <Scalar T>
Triangle<T>::Triangle() {}

template <Scalar T>
Triangle<T>::Triangle(const std::vector<Point<T>> &points) {
    for (const auto &pt : points) {
        vertices.push_back(std::make_unique<Point<T>>(pt.x, pt.y));
    }
}

template <Scalar T>
Triangle<T>::Triangle(const Triangle<T> &other) {
    for (const auto &pt : other.vertices) {
        vertices.push_back(std::make_unique<Point<T>>(pt->x, pt->y));
    }
}

template <Scalar T>
Triangle<T>::Triangle(Triangle<T> &&other) noexcept : vertices(std::move(other.vertices)) {}

template <Scalar T>
Triangle<T> &Triangle<T>::operator=(const Triangle<T> &other) {
    if (this != &other) {
        vertices.clear();
        for (const auto &pt : other.vertices) {
            vertices.push_back(std::make_unique<Point<T>>(pt->x, pt->y));
        }
    }
    return *this;
}

template <Scalar T>
Triangle<T> &Triangle<T>::operator=(Triangle<T> &&other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

template <Scalar T>
bool Triangle<T>::operator==(const Triangle<T> &other) const {
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
std::unique_ptr<Point<double>> Triangle<T>::Center() const {
    return PolygonCenter(vertices);
}

template <Scalar T>
void Triangle<T>::Print(std::ostream &os) const {
    os << "Triangle vertices: ";
    for (const auto &vertex : vertices) {
        os << *vertex << " ";
    }
    os << std::endl;
}

template <Scalar T>
void Triangle<T>::Read(std::istream &is) {
    vertices.clear();
    std::cout << "Введите 3 вершины (x y): ";
    for (int i = 0; i < 3; ++i) {
        T x, y;
        is >> x >> y;
        vertices.push_back(std::make_unique<Point<T>>(x, y));
    }
}

template <Scalar T>
Triangle<T>::operator double() const {
    return PolygonArea(vertices);
}