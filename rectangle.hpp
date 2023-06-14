#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "object.hpp"

using namespace std;

class Rectangle : public Object
{
    private:
        sf::RenderWindow *window;
        sf::RectangleShape rectangle;

        sf::Vector2f statisPos;
        sf::Vector2f dynamicPos;

    public:
        Rectangle(sf::RenderWindow *window, sf::Vector2f pos);
        void Render() override;
        void Update() override;
};

#endif