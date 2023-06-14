#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "object.hpp"

class Rectangle : public Object
{
    private:
        sf::RenderWindow *window;
        sf::RectangleShape rectangle;

    public:
        Rectangle(sf::RenderWindow *window, sf::Vector2f pos);
        void Render() override;
};

#endif