#ifndef DEBUG_TEXT_HPP
#define DEBUG_TEXT_HPP

#include <SFML/Graphics.hpp>

using namespace std;

class DebugText
{
    private:
        sf::RenderWindow *window;
        sf::Text text;
        sf::Font font;

    public:
        DebugText(sf::RenderWindow *window);
        void Render(string info);
};

#endif