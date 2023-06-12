#include "grid.h"

Grid::Grid(sf::RenderWindow *window, float width, float height)
{
    this->window = window;
    scale = 4.f;

    if (!texture.loadFromFile("grid.jpg", sf::IntRect(
            0, 
            0, 
            width * scale, 
            height * scale)
        )) {
        throw;
    }
    sprite.setTexture(texture);
    sprite.scale(1/scale, 1/scale);
    sprite.setPosition(sf::Vector2f(-width/2, -height/2));
}

void Grid::Render()
{
    window->draw(sprite);
}