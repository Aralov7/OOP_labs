#pragma once

#include <memory>
#include <string>
#include <cmath>

struct Vec2 {
public:
    Vec2() = default;
    Vec2(double x, double y);
    void Normalize();
    double GetLenght() const;
    Vec2& operator+=(const Vec2& rhs);
    Vec2& operator-=(const Vec2& rhs);
    Vec2& operator*=(double scalar);
    Vec2& operator/=(double scalar);
    Vec2 operator*(double scalar);
    Vec2 operator/(double scalar);
    Vec2 operator+(double scalar);
    Vec2 operator-(double scalar);
public:
    double x;
    double y;
};

class Character {
public:
    Character(const std::string& name, double x, double y, float stepSize, float attackRange);
    const std::string& GetName() const noexcept;
    double GetPosX() const noexcept;
    double GetPosY() const noexcept;
    virtual std::string GetType() const = 0;
    bool IsAlive() const;
    void Kill();
    void Move(Vec2 dir);
    float GetAttackRange() const;
    void SetPosition(const Vec2& p);
    virtual bool Beats(const Character& other) const = 0;
    virtual ~Character() = default;
protected:
    std::string name;
    Vec2 pos;
    bool isAlive = true;
    float stepSize;
    float attackRange;
};

class Dragon : public Character {
public:
    Dragon(const std::string& name, double x, double y);
    std::string GetType() const override;
    bool Beats(const Character& other) const override;
};

class Bull : public Character {
public:
    Bull(const std::string& name, double x, double y);
    std::string GetType() const override;
    bool Beats(const Character& other) const override;
};

class Frog : public Character {
public:
    Frog(const std::string& name, double x, double y);
    std::string GetType() const override;
    bool Beats(const Character& other) const override;
};