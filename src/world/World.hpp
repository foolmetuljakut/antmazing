#ifndef WORLD_HPP
#define WORLD_HPP

#include "Ant.hpp"
#include <vector>

class World {
public:
    std::vector<Ant> ants;
    World() {
        ants.push_back(std::move(Ant(500, 400)));
        ants.push_back(std::move(Ant(300, 400)));
        ants.push_back(std::move(Ant(300, 200)));
    }
};

#endif // !WORLD_HPP
