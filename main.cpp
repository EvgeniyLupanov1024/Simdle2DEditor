#include <SFML/Graphics.hpp>

#include "camera.h"

using namespace std;

int screenWidth = 900;
int screenHeight = 600;
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Best editor");
sf::Color backgroundColor(250, 230, 200, 255);

Camera camera(0, 0, screenWidth, screenHeight, &window);
sf::Vector2f getOffset();

sf::Event event;
void EventHandler();

bool keys[1024];
sf::Vector2i mousePos(0, 0);
sf::Text tMousePos;
sf::Font font;
sf::Color debugCol(110, 50, 100, 200);

sf::Texture texture;
sf::Sprite sprite;
float scale(3.3f);

void init()
{
    if (!texture.loadFromFile("grid.jpg", sf::IntRect(
            -screenWidth * scale / 2, 
            -screenHeight * scale / 2, 
            screenWidth * scale, 
            screenHeight * scale)
        )) {
        throw;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(-screenWidth/2, -screenHeight/2));
    sprite.scale(1/scale, 1/scale);

    if (!font.loadFromFile("arial.ttf")) {
        throw;
    }

    tMousePos.setFont(font);
    tMousePos.setCharacterSize(16);
    tMousePos.setFillColor(debugCol);
}

int main()
{
    init();

    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        EventHandler();

        window.clear(backgroundColor);
        
        camera.Update(getOffset());
        window.draw(sprite);

        window.setView(window.getDefaultView());
        tMousePos.setString("x:" + to_string(mousePos.x) + "| y:" + to_string(mousePos.y));
        window.draw(tMousePos);

        window.display();
    }

    return 0;
}

void EventHandler()
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break; 

        case sf::Event::Resized:
        {
            screenWidth =  event.size.width;
            screenHeight =  event.size.height;
            break; 
        }

        case sf::Event::KeyPressed:
            
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            keys[event.key.code] = true;
            break;

        case sf::Event::KeyReleased:
            keys[event.key.code] = false;
            break;

        case sf::Event::MouseMoved:
        {
            mousePos.x = event.mouseMove.x;
            mousePos.y = event.mouseMove.y;
            break; 
        }

        case sf::Event::MouseButtonPressed:
        {
            // event.mouseButton.x;
            // event.mouseButton.y;
            break; 
        }

        case sf::Event::MouseWheelScrolled:
        {
            camera.Zoom(event.mouseWheelScroll.delta);
            break; 
        }
        
        default:
            break;
        }
    }
}

sf::Vector2f getOffset()
{
    return sf::Vector2f(
        (keys[sf::Keyboard::Right] || keys[sf::Keyboard::D]) - (keys[sf::Keyboard::Left] || keys[sf::Keyboard::A]),
        (keys[sf::Keyboard::Down] || keys[sf::Keyboard::S]) - (keys[sf::Keyboard::Up] || keys[sf::Keyboard::W])
    );
}