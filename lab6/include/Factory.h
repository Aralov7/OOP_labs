#pragma once

#include "Character.h"
#include <memory>
#include <stdexcept>

class Factory {
public:
    static std::shared_ptr<Character> CreateCharacter(const std::string& type, const std::string& name, double x, double y);
};