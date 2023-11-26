#ifndef WORLD_HPP
#define WORLD_HPP

#include "Ant.hpp"
#include <vector>

class World {
public:
    size_t width, height;
    float dt, pheromoneRate;
    sf::Image pheromoneSpace;
    sf::Texture pheromoneTexture;
    sf::Sprite pheromoneSprite;
    std::vector<Ant> ants;

    World(size_t width, size_t height, float dt, float pheromoneRate) 
        : width{width}, height{height}, dt(dt), pheromoneRate(pheromoneRate) {
        
        pheromoneSpace.create(width, height, sf::Color::Black);

        ants.push_back(std::move(Ant(500, 400)));
        ants.push_back(std::move(Ant(300, 400)));
        ants.push_back(std::move(Ant(300, 200)));
    }

    void recordTrail() {
        for(auto& ant : ants) {
            size_t i = static_cast<size_t>(ant.pos.x),
                j = static_cast<size_t>(ant.pos.y);

            if(i < width && j < height) {
                int dp = (int)(100 * pheromoneRate * dt + 0.5f);
                dp = dp > 255 ? 255 : (dp < 0 ? 0 : dp);
                pheromoneSpace.setPixel(i, j, sf::Color(dp, dp, dp) + pheromoneSpace.getPixel(i, j));
            }
        }
        pheromoneTexture.loadFromImage(pheromoneSpace);
        pheromoneSprite.setTexture(pheromoneTexture, true);
    }

    void updateMechanics() {
        recordTrail();
    }
};

#endif // !WORLD_HPP
