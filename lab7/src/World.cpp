#include "../include/World.h"

// Реализация конструктора
World::World(double size) : worldSize(size) {}

// Реализация метода AddCharacter
void World::AddCharacter(const std::string& type, const std::string& name, double x, double y) {
    characters.push_back(Factory::CreateCharacter(type, name, x, y));
}

// Реализация метода AnounceFighters
void World::AnounceFighters() const {
    for (const auto& c : characters) {
        if (!c->IsAlive())
            continue;

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

// Реализация метода MoveCharacters
void World::MoveCharacters() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    for (auto c : characters) {
        Vec2 dir = Vec2{ dist(rng), dist(rng) };
        c->Move(dir);

        c->SetPosition(Vec2{ std::clamp(c->GetPosX(), 0.0, worldSize), std::clamp(c->GetPosY(), 0.0, worldSize) });
    }
}

// Реализация метода PrintMap
void World::PrintMap() const {
    int xSize = static_cast<int>(worldSize);
    int ySize = static_cast<int>(worldSize);

    for (int i = 0; i <= xSize + 2; ++i) {
        std::cout << '-';
    }
    std::cout << '\n';

    for (int i = 0; i <= ySize; ++i) {
        std::cout << '|';
        for (int j = 0; j <= xSize; ++j) {
            bool printed = false;
            for (auto c : characters) {
                if (!c->IsAlive())
                    continue;

                printed = true;
                if (static_cast<int>(c->GetPosX()) == j && static_cast<int>(c->GetPosY()) == i) {
                    if (c->GetType() == "Bull") {
                        std::cout << '^';
                        break;
                    }
                    else if (c->GetType() == "Dragon") {
                        std::cout << '*';
                        break;
                    }
                    else if (c->GetType() == "Frog") {
                        std::cout << '@';
                        break;
                    }
                }
                else {
                    printed = false;
                }
            }
            if (!printed) {
                std::cout << ' ';
            }
        }
        std::cout << '|';
        std::cout << '\n';
    }

    for (int i = 0; i <= xSize + 2; ++i) {
        std::cout << '-';
    }
    std::cout << '\n';
}

// Реализация метода GetSize
double World::GetSize() const {
    return worldSize;
}