#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>

class Grid
{
    private:
        sf::RenderWindow *window;
        sf::Texture texture;
        sf::Sprite sprite;
        float scale;

    public:
        Grid(sf::RenderWindow *window, float width, float height);
        void Render();
};

#endif