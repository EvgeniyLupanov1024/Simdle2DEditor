#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Camera
{
    private:
        sf::RenderWindow *window;
        sf::View view;

        sf::Vector2f speedMovement;
        float mass;
        float resistanceMovement;

        float zoom;

    public:
        Camera(float positionX, float positionY, float sizeX, float sizeY, sf::RenderWindow *window);
        void Update(sf::Vector2f acceleration);
        void Zoom(float zoomModule);
};

#endif