#pragma once

#include <vector>
#include <string>
#include <memory>

#include "Factory.h"
#include "Character.h"
#include "Visitor.h"

class World {
public:
    void AddCharacter(const std::string& type, const std::string& name, double x, double y);
    void AnounceFighters() const;
    void Serialize(const std::string& filename) const;
    void Deserialize(const std::string& filename);
    void Engage(Visitor& visitor);
private:
    std::vector<std::shared_ptr<Character>> characters;
};