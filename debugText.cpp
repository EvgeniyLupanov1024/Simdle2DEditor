#include "debugText.hpp"

DebugText::DebugText(sf::RenderWindow *window)
{
    this->window = window;

    if (!font.loadFromFile("arial.ttf")) {
        throw;
    }

    text.setFont(font);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color(110, 50, 100, 200));
}

void DebugText::Render(string info)
{
    text.setString(info);
    window->draw(text);
}