#ifndef FLOWER_HPP
#define FLOWER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <iostream>

#include "object.hpp"

using namespace std;

enum class GrowingStatus
{
    setSize,
    growing
};

class Flower : public Object
{
    private:
        sf::RenderWindow *window;

        float commonSize = 30;

        vector<sf::CircleShape *> backLeaf;
        sf::Transform tBackLeaf;
        float deviationAngleBack;
        float currentDeviationAngleBack;
        void FloverBack();

        vector<sf::CircleShape *> medianPetals;
        sf::Transform tMedianPetals;
        float deviationAngleMedian;
        float currentDeviationAngleMedian;
        void FloverMedian();

        vector<sf::CircleShape *> innerPetals;
        sf::Transform tInnerPetals;
        float deviationAngleFront;
        float currentDeviationAngleFront;
        void FloverFront();

        GrowingStatus growingStatus = GrowingStatus::setSize;

        sf::Vector2f statisPos;
        sf::Vector2f dynamicPos;

    public:
        Flower(sf::RenderWindow *window, sf::Vector2f pos);
        void Render() override;
        void Update() override;
};

#endif