#include <SFML/Graphics.hpp>
#include "Header.h"
#include "Fruit.h"
#include "Walls.h"
#include "Snake.h"
#include "Menu.h"

using namespace sf;

extern const int g_FIELD_WIDTH = 25;
extern const int g_FIELD_HEIGHT = 25;
extern const int g_TABLE_WIDTH = 10;
extern const int g_CELL = 20;

int main()
{// cglazhivanie
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    setlocale(LC_ALL, "rus");

    

    RenderWindow window(sf::VideoMode((g_FIELD_WIDTH + g_TABLE_WIDTH) * g_CELL
        , g_FIELD_HEIGHT * g_CELL), "Snake");

    // TODO сделать размер отношением 20/g_CELL;

    Fruit fruit;
    Walls wall;

    Font font;
    font.loadFromFile("D:\VS\\snake_font.otf");

    Menu menu(font);

    while (window.isOpen())
    {
        while (menu.IsActive()) {    
            window.clear(sf::Color(190, 228, 255, 0));
            menu.Render(window);

            Event event;
            while (window.pollEvent(event))
            {   if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Up) {
                        menu.Up();
                    }
                    if (event.key.code == Keyboard::Down) {
                        menu.Down();
                    }
                    if (event.key.code == Keyboard::Enter) {
                        if (menu.Go() == 2) {
                            window.close();
                        };
                    }
                    else if (event.key.code == Keyboard::Escape) {
                        window.close();
                    }
                }
            }
            window.display();
        }
        //стены
        bool game = true;

        coord now{ g_FIELD_WIDTH / 2, g_FIELD_HEIGHT / 2, 0};
        coord change{ -1,0,0 };

        Snake snake("name");
        while (game) {

            window.clear(Color(190, 228, 255, 0));
            wall.Render(window);
            sf::Event event;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Up) {
                        change = { 0, -1 , 1 };
                    }
                    else if (event.key.code == Keyboard::Down) {
                        change = { 0, +1 , 3 };
                    }
                    else if (event.key.code == Keyboard::Left) {
                        change = { -1, 0 , 0 };
                    }
                    else if (event.key.code == Keyboard::Right) {
                        change = { +1, 0 , 2 };
                    }
                }
            }

            now.x += change.x;
            now.y += change.y;
            now.direction = change.direction;

            if (!snake.Go(now.x, now.y, now.direction) || wall.Here(now.x,now.y)) {
                Text text("You died, again?\n Y/N", font, 2 * g_CELL);
                text.setPosition({ 2 * g_CELL, (g_FIELD_HEIGHT / 2 - 6) * g_CELL });
                window.draw(text);
                window.display();
                bool end = true;
                while (end) {
                    Event event;
                    while (window.pollEvent(event))
                    {
                        if (event.type == Event::KeyPressed) {
                            if (event.key.code == Keyboard::Y) {
                                end = false;
                                game = false;
                            }
                            else if (event.key.code == Keyboard::N) {
                                menu.Activate();
                                game = false;
                                end = false;
                            }
                        }
                    }
                }
            };

            snake.Render(window);

            if (abs(now.x - fruit.Getx()) < 0.1 && abs(now.y - fruit.Gety()) < 0.1) {
                snake.EatFood();
                fruit.CreateFruit();
            }
            fruit.Render(window);

            window.display();
            Time stop = seconds(0.5f);
            sf::sleep(stop);
        }
    }

    return 0;
}
