#ifndef SENSORYINPUT_HPP
#define SENSORYINPUT_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

class SensoryInput {
public:
    float viewingRange;
    float da;
    size_t visionSegments;
    SensoryInput(float viewingRange, size_t visionSegments) : viewingRange{viewingRange}, da{2*M_PI / visionSegments}, visionSegments{visionSegments} {}
    
    std::vector<float> parse2dField(const sf::Image& scalarField, sf::Vector2u&& referencePosition) {
        std::vector<float> angularVision;
        for(size_t i = 0; i < visionSegments; i++)
            angularVision.push_back(i);

        size_t xm = static_cast<size_t>(referencePosition.x - viewingRange),
                xp = static_cast<size_t>(referencePosition.x + viewingRange),
                ym = static_cast<size_t>(referencePosition.y - viewingRange),
                yp = static_cast<size_t>(referencePosition.y + viewingRange);

        for(size_t x = xm; x <= xp; x++)
            for(size_t y = ym; y <= yp; y++) {
                size_t Q = (x - referencePosition.x)*(x - referencePosition.x) + 
                            (y - referencePosition.y)*(y - referencePosition.y);
                if(Q > 0 and Q < viewingRange*viewingRange) {
                    float a = atan2(y - referencePosition.y, x - referencePosition.x);
                    size_t ai = static_cast<size_t>(round(a / da));
                    sf::Color localColor= scalarField.getPixel(x, y);
                    float v = (localColor.r + localColor.g + localColor.b) / 3.0f;
                    angularVision[ai] += v;
                }
            }
        
        return angularVision;
    }
};

#endif //SENSORYINPUT_HPP