#include "flower.hpp"

void Flower::FloverBack()
{
    float size = 27.f;
    int leafCount = 5;

    for (int i = 0; i < leafCount; i++)
    {
        sf::CircleShape leaf(size, 4);
        leaf.setPosition(statisPos);

        leaf.setFillColor(sf::Color(106, 161, 122));
        leaf.setOutlineThickness(3);
        leaf.setOutlineColor(sf::Color(161, 212, 201));

        leaf.setOrigin(sf::Vector2f(size, size * 2));
        leaf.scale(0.9, 1);
        leaf.rotate((360/leafCount) * 2 * i + (360/(2*leafCount)));

        backLeaf.push_back(leaf);
    }
}

void Flower::FloverMedian()
{
    float size = 30.f;
    int petalsCount = 5;
    sf::CircleShape *petal;

    for (int i = 0; i < petalsCount; i++)
    {
        sf::CircleShape petal(size, 5);
        petal.setPosition(statisPos);

        petal.setFillColor(sf::Color(245, 155, 86));
        petal.setOutlineThickness(3);
        petal.setOutlineColor(sf::Color(255, 205, 89));

        petal.setOrigin(sf::Vector2f(size, size * 2));
        petal.scale(0.5, 1);
        petal.rotate((360/petalsCount) * 2 * i);

        medianPetals.push_back(petal);
    }
}

void Flower::FloverFront()
{
    float size = 20.f;
    int petalsCount = 10;
    sf::CircleShape *petal;

    for (int i = 0; i < petalsCount; i++)
    {
        sf::CircleShape petal(size, 6);
        petal.setPosition(statisPos);

        petal.setFillColor(sf::Color(252, 243, 204));
        petal.setOutlineThickness(3);
        petal.setOutlineColor(sf::Color(252, 228, 227));

        petal.setOrigin(sf::Vector2f(size, size * 2));
        petal.scale(0.2, 1);
        petal.rotate((360/petalsCount) * 3 * i);

        innerPetals.push_back(petal);
    }
}

Flower::Flower(sf::RenderWindow *window, sf::Vector2f pos)
{
    this->window = window;
    statisPos = pos;

    FloverBack();
    FloverMedian();
    FloverFront();

    Object::status = UpdateStatus::NotUpdate;
}

void Flower::Render()
{
    for (sf::CircleShape leaf : backLeaf) {
        window->draw(leaf);
    }

    for (sf::CircleShape petal : medianPetals) {
        window->draw(petal);
    }

    for (sf::CircleShape petal : innerPetals) {
        window->draw(petal);
    }
}

void Flower::Update()
{

}