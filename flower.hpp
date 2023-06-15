#ifndef FLOWER_HPP
#define FLOWER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "object.hpp"

using namespace std;

class Flower : public Object
{
    private:
        sf::RenderWindow *window;

        vector<sf::CircleShape> backLeaf;
        void FloverBack();

        vector<sf::CircleShape> medianPetals;
        void FloverMedian();

        vector<sf::CircleShape> innerPetals;
        void FloverFront();

        sf::Vector2f statisPos;
        sf::Vector2f dynamicPos;

    public:
        Flower(sf::RenderWindow *window, sf::Vector2f pos);
        void Render() override;
        void Update() override;
};

#endif