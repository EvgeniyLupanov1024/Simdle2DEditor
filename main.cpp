#include <SFML/Graphics.hpp>

using namespace std;

int screenWidth = 900;
int screenHeight = 600;
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Best editor");
sf::Color backgroundColor(250, 230, 200, 255);

sf::Event event;
void EventHandler();

sf::Vector2i mousePos(0, 0);
sf::Text tMousePos;
sf::Font font;
sf::Color debugCol(110, 50, 100, 200);

void init()
{
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

    while (window.isOpen())
    {
        EventHandler();

        window.clear(backgroundColor);

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
            // event.mouseWheelScroll.delta;
            // event.mouseWheelScroll.x;
            // event.mouseWheelScroll.y; --
            break; 
        }
        
        default:
            break;
        }
    }
}