#ifndef GRID_HPP
#define GRID_HPP

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