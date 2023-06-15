#include "flower.hpp"

sf::Color MakeRandomColor(int del, int r, int g, int b, int a)
{
    return sf::Color(
        r + (rand() % (del*2) - del), 
        g + (rand() % (del*2) - del), 
        b + (rand() % (del*2) - del),
        a
    );
}

float MakeRandomAngle(int angle, int del)
{
    return angle + (rand() % (del*2) - del);
}

void Flower::FloverBack()
{
    float size = commonSize * 0.9f;
    tBackLeaf.scale(0, 0);
    deviationAngleBack = MakeRandomAngle(80, 20) * rotateDirection;
    currentDeviationAngleBack = deviationAngleBack;
    int leafCount = 5;

    sf::CircleShape *leaf;
    sf::Color randFillColor = MakeRandomColor(40, 106, 161, 122, 100);
    sf::Color randOutlineColor = MakeRandomColor(10, 161, 212, 201, 150);
    for (int i = 0; i < leafCount; i++)
    {
        leaf = new sf::CircleShape(size, 4);
        leaf->setPosition(statisPos);

        leaf->setFillColor(randFillColor);
        leaf->setOutlineThickness(3);
        leaf->setOutlineColor(randOutlineColor);

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
    deviationAngleMedian = MakeRandomAngle(90, 20) * rotateDirection;
    currentDeviationAngleMedian = deviationAngleMedian;
    int petalsCount = 5;

    sf::CircleShape *petal;
    sf::Color randFillColor = MakeRandomColor(40, 244, 155, 86, 100);
    sf::Color randOutlineColor = MakeRandomColor(10, 244, 205, 89, 150);
    for (int i = 0; i < petalsCount; i++)
    {
        sf::CircleShape* petal = new sf::CircleShape(size, 5);
        petal->setPosition(statisPos);

        petal->setFillColor(randFillColor);
        petal->setOutlineThickness(3);
        petal->setOutlineColor(randOutlineColor);

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
    deviationAngleFront = MakeRandomAngle(100, 20) * rotateDirection;
    currentDeviationAngleFront = deviationAngleFront;
    int petalsCount = 10;
    
    sf::CircleShape *petal;
    sf::Color randFillColor = MakeRandomColor(10, 242, 243, 204, 100);
    sf::Color randOutlineColor = MakeRandomColor(10, 242, 228, 227, 150);
    for (int i = 0; i < petalsCount; i++)
    {
        sf::CircleShape* petal = new sf::CircleShape(size, 6);
        petal->setPosition(statisPos);

        petal->setFillColor(randFillColor);
        petal->setOutlineThickness(3);
        petal->setOutlineColor(randOutlineColor);

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
    rotateDirection = rand() % 2 == 1 ? 1 : -1;

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

float deviationBack, deviationMedian, deviationFront;
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

            tBackLeaf.rotate(-deviationAngleBack, statisPos.x, statisPos.y);
            tMedianPetals.rotate(-deviationAngleMedian, statisPos.x, statisPos.y);
            tInnerPetals.rotate(-deviationAngleFront, statisPos.x, statisPos.y);

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

    case GrowingStatus::growing:

        if (abs(currentDeviationAngleBack) > 0.05) {
            deviationBack = (currentDeviationAngleBack * 13 / deviationAngleBack) * rotateDirection;
            currentDeviationAngleBack -= deviationBack;
            tBackLeaf.rotate(deviationBack, statisPos.x, statisPos.y);
        }

        if (abs(currentDeviationAngleMedian) > 0.05) {
            deviationMedian = (currentDeviationAngleMedian * 7 / deviationAngleMedian) * rotateDirection;
            currentDeviationAngleMedian -= deviationMedian;
            tMedianPetals.rotate(deviationMedian, statisPos.x, statisPos.y);
        }

        if (abs(currentDeviationAngleFront) > 0.05) {
            deviationFront = (currentDeviationAngleFront * 4 / deviationAngleFront) * rotateDirection;
            currentDeviationAngleFront -= deviationFront;
            tInnerPetals.rotate(deviationFront, statisPos.x, statisPos.y);
        }

        if (abs(currentDeviationAngleBack) <= 0.05 && abs(currentDeviationAngleMedian) <= 0.05 && abs(currentDeviationAngleFront) <= 0.05) {
            Object::status = UpdateStatus::EndUpdate;
        }

        break;
    
    default:
        break;
    }
}