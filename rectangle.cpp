#include "rectangle.hpp"

Rectangle::Rectangle(sf::RenderWindow *window, sf::Vector2f pos)
{
    this->window = window;
    statisPos = pos;

    rectangle = sf::RectangleShape(sf::Vector2f(1.f, 1.f));
    rectangle.setFillColor(sf::Color(220, 50, 40, 100));
    rectangle.setOutlineThickness(2.f);
    rectangle.setOutlineColor(sf::Color(250, 250, 200, 150));
    rectangle.setPosition(pos);

    Object::status = UpdateStatus::Update;
}

void Rectangle::Render()
{
    window->draw(rectangle);
}

float posX, posY, sizeX, sizeY;
void Rectangle::Update()
{
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Object::status = UpdateStatus::EndUpdate;
        rectangle.setFillColor(sf::Color(220, 50, 40, 240));
        rectangle.setOutlineColor(sf::Color(250, 150, 100, 240));
    }

    dynamicPos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

    posX = min(statisPos.x, dynamicPos.x);
    posY = min(statisPos.y, dynamicPos.y);

    sizeX = abs(statisPos.x - dynamicPos.x);
    sizeY = abs(statisPos.y - dynamicPos.y);

    rectangle.setPosition(sf::Vector2f(posX, posY));
    rectangle.setSize(sf::Vector2f(sizeX, sizeY));
}