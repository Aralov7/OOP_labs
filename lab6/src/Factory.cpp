#include "../include/Factory.h"

std::shared_ptr<Character> Factory::CreateCharacter(const std::string& type, const std::string& name, double x, double y) {
    if (type == "Dragon") {
        return std::make_shared<Dragon>(name, x, y);
    }
    else if (type == "Bull") {
        return std::make_shared<Bull>(name, x, y);
    }
    else if (type == "Frog") {
        return std::make_shared<Frog>(name, x, y);
    }
    else {
        throw std::invalid_argument("Unknown NPC type: " + type);
    }
}