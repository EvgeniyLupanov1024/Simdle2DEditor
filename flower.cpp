#include "flower.hpp"

Flower::Flower(sf::RenderWindow *window, sf::Vector2f pos)
{
    this->window = window;
    statisPos = pos;

    circleShape = sf::CircleShape(80, 4);
    circleShape.setPosition(pos);
    circleShape.setFillColor(sf::Color(170, 150, 50));

    Object::status = UpdateStatus::NotUpdate;
}

void Flower::Render()
{
    window->draw(circleShape);
}

void Flower::Update()
{

}