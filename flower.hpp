#ifndef FLOWER_HPP
#define FLOWER_HPP

#include <SFML/Graphics.hpp>
#include "object.hpp"

using namespace std;

class Flower : public Object
{
    private:
        sf::RenderWindow *window;
        sf::CircleShape circleShape;

        sf::Vector2f statisPos;
        sf::Vector2f dynamicPos;

    public:
        Flower(sf::RenderWindow *window, sf::Vector2f pos);
        void Render() override;
        void Update() override;
};

#endif