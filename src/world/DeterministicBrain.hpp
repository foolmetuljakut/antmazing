#ifndef DETERMINISTICBRAIN
#define DETERMINISTICBRAIN

#include "SensoryInput.hpp"

class DeterministicBrain {
    SensoryInput trafo;
public:
    DeterministicBrain(float viewingRange, size_t visionSegments) 
        : trafo(viewingRange, visionSegments) {}
    float makeDecision(const sf::Image& field, const sf::Vector2f refPos) {
        std::vector<float> vision = trafo.parse2dField(field, 
            std::move(sf::Vector2u(static_cast<size_t>(round(refPos.x)), static_cast<size_t>(round(refPos.y)))));
        
        size_t maxi = 0, maxv = vision[0];
        for(size_t i = 0; i < vision.size(); i++)
            if(maxv < vision[i]) {
                maxi = i;
                maxv = vision[i];
            }
        return maxi * trafo.da;
    }
};

#endif //DETERMINISTICBRAIN