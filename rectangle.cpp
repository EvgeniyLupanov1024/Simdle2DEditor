#include "rectangle.hpp"

Rectangle::Rectangle(sf::RenderWindow *window)
{
    this->window = window;

    rectangle = sf::RectangleShape(sf::Vector2f(100.f, 50.f));
    rectangle.setFillColor(sf::Color(220, 50, 40, 240));
    rectangle.setOutlineThickness(2.f);
    rectangle.setOutlineColor(sf::Color(250, 150, 100));
}

void Rectangle::Render()
{
    window->draw(rectangle);
}