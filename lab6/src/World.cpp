#include "../include/World.h"
#include <fstream>
#include <iostream>

// Реализация метода AddCharacter
void World::AddCharacter(const std::string& type, const std::string& name, double x, double y) {
    characters.push_back(Factory::CreateCharacter(type, name, x, y));
}

// Реализация метода AnounceFighters
void World::AnounceFighters() const {
    for (const auto& c : characters) {
        std::cout << c->GetType() << " '" << c->GetName() << "' ("
                  << c->GetPosX() << ", " << c->GetPosY() << ")\n";
    }
}

// Реализация метода Serialize
void World::Serialize(const std::string& filename) const {
    std::ofstream fs(filename);
    if (!fs.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }
    for (const auto& c : characters) {
        fs << c->GetType() << " " << c->GetName() << " "
           << c->GetPosX() << " " << c->GetPosY() << "\n";
    }
}

// Реализация метода Deserialize
void World::Deserialize(const std::string& filename) {
    std::ifstream fs(filename);
    if (!fs.is_open()) {
        throw std::runtime_error("Failed to open file for reading: " + filename);
    }
    std::string type, name;
    double x, y;
    while (fs >> type >> name >> x >> y) {
        AddCharacter(type, name, x, y);
    }
}

// Реализация метода Engage
void World::Engage(Visitor& visitor) {
    visitor.Engage(characters);
}