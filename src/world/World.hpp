#ifndef WORLD_HPP
#define WORLD_HPP

#include "Ant.hpp"
#include <vector>

class World {

    void initPheromoneSpace() {
        pheromoneSpace = new float*[width];
        for(size_t i = 0; i < width; i++) {
            pheromoneSpace[i] = new float[height]; 
            for(size_t j = 0; j < height; j++){
                pheromoneSpace[i][j] = 0;
            }
        }
    }

public:
    size_t width, height;
    float dt, pheromoneRate;
    float **pheromoneSpace;
    std::vector<Ant> ants;

    World(size_t width, size_t height, float&& dt, float&& pheromoneRate) 
        : width{width}, height{height}, dt(std::move(dt)), pheromoneRate(std::move(pheromoneRate)) {
        initPheromoneSpace();
        ants.push_back(std::move(Ant(500, 400)));
        ants.push_back(std::move(Ant(300, 400)));
        ants.push_back(std::move(Ant(300, 200)));
    }

    void recordTrail() {
        for(auto& ant : ants) {
            size_t i = static_cast<size_t>(ant.pos.x),
                j = static_cast<size_t>(ant.pos.y);
            if(i < width && j < height)
                pheromoneSpace[i][j] += pheromoneRate * dt;
        }
    }

    ~World() {
        for(size_t i = 0; i < width; i++) {
            delete[] pheromoneSpace[i];
        }
        delete[] pheromoneSpace;
    }
};

#endif // !WORLD_HPP
