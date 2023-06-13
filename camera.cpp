#include "camera.hpp"

Camera::Camera(float positionX, float positionY, float sizeX, float sizeY, sf::RenderWindow *window)
{
    this->window = window;
    this->view.setCenter(sf::Vector2f(positionX, positionY));
    this->view.setSize(sf::Vector2f(sizeX, sizeY));

    this->speedMovement = sf::Vector2f(0.f, 0.f);
    this->mass = 1.f;
    this->resistanceMovement = 1.15f;

    this->zoom = 1.f;

    window->setView(this->view);
}

sf::Vector2f normalize(const sf::Vector2f& source)
{
    float length = std::sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
        return sf::Vector2f(source.x / length, source.y / length);
    else
        return source;
}

void Camera::Update(sf::Vector2f acceleration)
{
    speedMovement += normalize(acceleration) * zoom * zoom / mass;
    view.move(speedMovement);
    speedMovement /= resistanceMovement;

    window->setView(this->view);
}

void Camera::Zoom(float zoomModule)
{
    view.zoom(zoom + zoomModule * 0.1);
}