#include "rectangle.hpp"

Rectangle::Rectangle(sf::RenderWindow *window, sf::Vector2f pos)
{
    this->window = window;

    rectangle = sf::RectangleShape(sf::Vector2f(100.f, 50.f));
    rectangle.setFillColor(sf::Color(220, 50, 40, 240));
    rectangle.setOutlineThickness(2.f);
    rectangle.setOutlineColor(sf::Color(250, 150, 100));
    rectangle.setPosition(pos);

    Object::status = UpdateStatus::Update;
}

void Rectangle::Render()
{
    window->draw(rectangle);
}

void Rectangle::Update()
{
}