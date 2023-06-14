#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>

class Rectangle
{
    private:
        sf::RenderWindow *window;
        sf::RectangleShape rectangle;

    public:
        Rectangle(sf::RenderWindow *window);
        void Render();
};

#endif