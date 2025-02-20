#pragma once

#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

#include "Character.h"
#include "Observer.h"

class Visitor {
public:
    Visitor(double range);
    void AddObserver(EventObserver* observer);
    void Engage(std::vector<std::shared_ptr<Character>>& characters);
private:
    void Announce(const std::string& event);
    double attackRange;
    std::vector<EventObserver*> observers;
};