#pragma once

#include <vector>
#include <memory>
#include <string>
#include <cmath>
#include <random>
#include <chrono>

#include "../include/Character.h"
#include "../include/Observer.h"

class Visitor {
public:
    Visitor(double range);
    Visitor() = default;
    void AddObserver(EventObserver* observer);
    void Engage(std::vector<std::shared_ptr<Character>>& characters);
private:
    double attackRange;
    void Announce(const std::string& event);
    std::vector<EventObserver*> observers;
};