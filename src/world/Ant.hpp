#ifndef ANT_HPP
#define ANT_HPP

#include <SFML/Graphics.hpp>
#include "DeterministicBrain.hpp"

class Ant {
public:
    sf::Vector2f pos;
    sf::CircleShape shape, viewingCircle;
    DeterministicBrain brain;

    Ant(float x, float y) : pos{x,y}, shape(5), viewingCircle(25), brain(25, 12) {
        shape.setFillColor(sf::Color(100, 250, 50));
        viewingCircle.setFillColor(sf::Color(30, 30, 30));
    }

    void refreshPosition() {
        pos.x += 1;
        shape.setPosition(pos - sf::Vector2f(5, 5));
        viewingCircle.setPosition(pos - sf::Vector2f(25, 25));
    }
};

#endif // ANT_HPP
