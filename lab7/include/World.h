#pragma once

#include <vector>
#include <string>
#include <memory>
#include <random>
#include <chrono>
#include <fstream>
#include <algorithm>

#include "Factory.h"
#include "Character.h"
#include "Visitor.h"

class World {
public:
    World(double size);
    World() = default;
    void AddCharacter(const std::string& type, const std::string& name, double x, double y);
    void AnounceFighters() const;
    void Serialize(const std::string& filename) const;
    void Deserialize(const std::string& filename);
    void Engage(Visitor& visitor);
    void MoveCharacters();
    void PrintMap() const;
    double GetSize() const;
private:
    double worldSize;
    std::vector<std::shared_ptr<Character>> characters;
};