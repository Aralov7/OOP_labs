#pragma once

#include <memory>
#include <string>

struct Position {
    double x;
    double y;
};

class Character {
public:
    Character(const std::string& name, double x, double y);
    const std::string& GetName() const noexcept;
    double GetPosX() const noexcept;
    double GetPosY() const noexcept;
    virtual std::string GetType() const = 0;
    bool IsAlive() const;
    void Kill();
    virtual bool Beats(const Character& other) const = 0;
    virtual ~Character() = default;
protected:
    std::string name;
    Position pos;
    bool isAlive = true;
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