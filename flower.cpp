#include "flower.hpp"

void Flower::FloverBack()
{
    float size = commonSize * 0.9f;
    tBackLeaf.scale(0, 0);
    int leafCount = 5;

    sf::CircleShape *leaf;

    for (int i = 0; i < leafCount; i++)
    {
        leaf = new sf::CircleShape(size, 4);
        leaf->setPosition(statisPos);

        leaf->setFillColor(sf::Color(106, 161, 122, 100));
        leaf->setOutlineThickness(3);
        leaf->setOutlineColor(sf::Color(161, 212, 201, 150));

        leaf->setOrigin(sf::Vector2f(size, size * 2));
        leaf->scale(0.9, 1);
        leaf->rotate((360/leafCount) * 2 * i + (360/(2*leafCount)));

        backLeaf.push_back(leaf);
    }
}

void Flower::FloverMedian()
{
    float size = commonSize;
    tMedianPetals.scale(0, 0);
    int petalsCount = 5;

    sf::CircleShape *petal;

    for (int i = 0; i < petalsCount; i++)
    {
        sf::CircleShape* petal = new sf::CircleShape(size, 5);
        petal->setPosition(statisPos);

        petal->setFillColor(sf::Color(245, 155, 86, 100));
        petal->setOutlineThickness(3);
        petal->setOutlineColor(sf::Color(255, 205, 89, 150));

        petal->setOrigin(sf::Vector2f(size, size * 2));
        petal->scale(0.5, 1);
        petal->rotate((360/petalsCount) * 2 * i);

        medianPetals.push_back(petal);
    }
}

void Flower::FloverFront()
{
    float size = commonSize * 0.66f;
    tInnerPetals.scale(0, 0);
    int petalsCount = 10;
    
    sf::CircleShape *petal;

    for (int i = 0; i < petalsCount; i++)
    {
        sf::CircleShape* petal = new sf::CircleShape(size, 6);
        petal->setPosition(statisPos);

        petal->setFillColor(sf::Color(252, 243, 204, 100));
        petal->setOutlineThickness(3);
        petal->setOutlineColor(sf::Color(252, 228, 227, 150));

        petal->setOrigin(sf::Vector2f(size, size * 2));
        petal->scale(0.2, 1);
        petal->rotate((360/petalsCount) * 3 * i);

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

    Object::status = UpdateStatus::Update;
}

void Flower::Render()
{
    for (sf::CircleShape *leaf : backLeaf) {
        window->draw(*leaf, tBackLeaf);
    }

    for (sf::CircleShape *petal : medianPetals) {
        window->draw(*petal, tMedianPetals);
    }

    for (sf::CircleShape *petal : innerPetals) {
        window->draw(*petal, tInnerPetals);
    }
}

void Flower::Update()
{
    switch (growingStatus)
    {
    case GrowingStatus::setSize:
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
        {
            dynamicPos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

            float sizeX = dynamicPos.x - statisPos.x;
            float sizeY = dynamicPos.y - statisPos.y;
            float newSize = sqrt(pow(sizeX, 2) + pow(sizeY, 2));
            float scale = newSize / (commonSize * 2);

            float angle = atan(sizeY / sizeX) * (180.0/M_PI) + (sizeX >= 0 ? 0 : -180) + 90;

            tBackLeaf = sf::Transform();
            tBackLeaf.scale(scale, scale, statisPos.x, statisPos.y);
            tBackLeaf.rotate(angle, statisPos.x, statisPos.y);

            tMedianPetals = tBackLeaf;
            tInnerPetals = tBackLeaf;
        }
        else
        {
            growingStatus = GrowingStatus::growing;

            for (sf::CircleShape *leaf : backLeaf) {
                leaf->setFillColor(leaf->getFillColor() + sf::Color(0, 0, 0, 140));
                leaf->setOutlineColor(leaf->getOutlineColor() + sf::Color(0, 0, 0, 90));
            }

            for (sf::CircleShape *petal : medianPetals) {
                petal->setFillColor(petal->getFillColor() + sf::Color(0, 0, 0, 140));
                petal->setOutlineColor(petal->getOutlineColor() + sf::Color(0, 0, 0, 90));
            }

            for (sf::CircleShape *petal : innerPetals) {
                petal->setFillColor(petal->getFillColor() + sf::Color(0, 0, 0, 140));
                petal->setOutlineColor(petal->getOutlineColor() + sf::Color(0, 0, 0, 90));
            }
        }

        break;
    
    default:
        break;
    }
}