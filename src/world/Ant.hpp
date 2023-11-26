#ifndef ANT_HPP
#define ANT_HPP

#include <SFML/Graphics.hpp>

class Ant {
public:
    sf::Vector2f pos;
    sf::CircleShape shape;

    Ant(float x, float y) : pos{x,y}, shape(5) {
        shape.setFillColor(sf::Color(100, 250, 50));
    }

    void refreshPosition() {
        shape.setPosition(pos);
    }
};

#endif // ANT_HPP
