#include "../include/Character.h"

// Реализация методов класса Character
Character::Character(const std::string& name, double x, double y)
    : name(name), pos({x, y}) {}

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

// Реализация методов класса Dragon
Dragon::Dragon(const std::string& name, double x, double y)
    : Character(name, x, y) {}

std::string Dragon::GetType() const {
    return "Dragon";
}

bool Dragon::Beats(const Character& other) const {
    return other.GetType() == "Bull";
}

// Реализация методов класса Bull
Bull::Bull(const std::string& name, double x, double y)
    : Character(name, x, y) {}

std::string Bull::GetType() const {
    return "Bull";
}

bool Bull::Beats(const Character& other) const {
    return other.GetType() == "Frog";
}

// Реализация методов класса Frog
Frog::Frog(const std::string& name, double x, double y)
    : Character(name, x, y) {}

std::string Frog::GetType() const {
    return "Frog";
}

bool Frog::Beats(const Character& other) const {
    return false;
}