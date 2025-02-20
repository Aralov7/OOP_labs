#include "../include/Character.h"

// Реализация методов Vec2
Vec2::Vec2(double x, double y) : x(x), y(y) {}

void Vec2::Normalize() {
    double length = GetLenght();
    if (length != 0) {
        x /= length;
        y /= length;
    }
}

double Vec2::GetLenght() const {
    return std::sqrt(x * x + y * y);
}

Vec2& Vec2::operator+=(const Vec2& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vec2& Vec2::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vec2& Vec2::operator/=(double scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

Vec2 Vec2::operator*(double scalar) {
    Vec2 result = *this;
    result.x *= scalar;
    result.y *= scalar;
    return result;
}

Vec2 Vec2::operator/(double scalar) {
    Vec2 result = *this;
    result.x /= scalar;
    result.y /= scalar;
    return result;
}

Vec2 Vec2::operator+(double scalar) {
    Vec2 result = *this;
    result.x += scalar;
    result.y += scalar;
    return result;
}

Vec2 Vec2::operator-(double scalar) {
    Vec2 result = *this;
    result.x -= scalar;
    result.y -= scalar;
    return result;
}

// Реализация методов Character
Character::Character(const std::string& name, double x, double y, float stepSize, float attackRange)
    : name(name), pos({x, y}), stepSize(stepSize), attackRange(attackRange) {}

const std::string& Character::GetName() const noexcept {
    return name;
}

double Character::GetPosX() const noexcept {
    return pos.x;
}

double Character::GetPosY() const noexcept {
    return pos.y;
}

bool Character::IsAlive() const {
    return isAlive;
}

void Character::Kill() {
    isAlive = false;
}

void Character::Move(Vec2 dir) {
    dir.Normalize();
    pos += dir * stepSize;
}

float Character::GetAttackRange() const {
    return attackRange;
}

void Character::SetPosition(const Vec2& p) {
    pos.x = p.x;
    pos.y = p.y;
}

// Реализация методов Dragon
Dragon::Dragon(const std::string& name, double x, double y)
    : Character(name, x, y, 50, 30) {}

std::string Dragon::GetType() const {
    return "Dragon";
}

bool Dragon::Beats(const Character& other) const {
    return other.GetType() == "Bull";
}

// Реализация методов Bull
Bull::Bull(const std::string& name, double x, double y)
    : Character(name, x, y, 30, 10) {}

std::string Bull::GetType() const {
    return "Bull";
}

bool Bull::Beats(const Character& other) const {
    return other.GetType() == "Frog";
}

// Реализация методов Frog
Frog::Frog(const std::string& name, double x, double y)
    : Character(name, x, y, 1, 10) {}

std::string Frog::GetType() const {
    return "Frog";
}

bool Frog::Beats(const Character&) const {
    return false;
}