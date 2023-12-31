#include <SFML/Graphics.hpp>
#include <iostream>

#include "camera.hpp"
#include "grid.hpp"
#include "debugText.hpp"
#include "scene.hpp"
#include "rectangle.hpp"
#include "flower.hpp"

using namespace std;

int screenWidth = 1500;
int screenHeight = 900;
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Best editor");
sf::Color backgroundColor(250, 230, 200, 255);

sf::Event event;
void EventHandler();
bool keys[1024];
sf::Vector2i mousePos(0, 0);

sf::Vector2f getOffset();
Camera camera(0, 0, screenWidth, screenHeight, &window);

Grid grid(&window, screenWidth, screenHeight);
DebugText debugText(&window);
Scene scene;

enum class DrawMode
{
    rectangle,
    flower
};
DrawMode drawMode = DrawMode::flower;

int main()
{
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        EventHandler();

        window.clear(backgroundColor);

        camera.Update(getOffset());
        
        grid.Render();
        scene.Render();
        scene.Update();

        window.setView(window.getDefaultView());
        debugText.Render("x:" + to_string(mousePos.x) + "| y:" + to_string(mousePos.y));

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

            switch (event.key.code)
            {
            case sf::Keyboard::Z:
                if (keys[sf::Keyboard::LControl]) {
                    scene.RemoveLastObject();
                }
                break;

            case sf::Keyboard::R:
                drawMode = DrawMode::rectangle;
                break;

            case sf::Keyboard::F:
                drawMode = DrawMode::flower;
                break;
            
            default:
                break;
            }

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
            window.setView(camera.view);
            sf::Vector2f worldCoord = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

            switch (drawMode)
            {
            case DrawMode::rectangle :
                scene.AddObject(new Rectangle(&window, worldCoord));
                break;

            case DrawMode::flower :
                scene.AddObject(new Flower(&window, worldCoord));
                break;
            
            default:
                break;
            }

            
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