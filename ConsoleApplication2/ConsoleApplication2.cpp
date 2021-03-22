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
extern const unsigned int g_CELL = 20;

int main()
{// cглаживание
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    setlocale(LC_ALL, "rus");
    // создаем окно
    RenderWindow window(sf::VideoMode((g_FIELD_WIDTH + g_TABLE_WIDTH) * g_CELL
        , g_FIELD_HEIGHT * g_CELL), "Snake");

    // текстуры и шрифт
    Font font;
    font.loadFromFile("res\\snake_font.otf");
    Menu menu(font);

    Texture snake_texture;
    snake_texture.loadFromFile("res\\snake.png");
    Snake snake(snake_texture);

    Texture fruits_texture;
    fruits_texture.loadFromFile("res\\fruits.png");
    Fruit fruit(fruits_texture);

    Texture wall_texture;
    wall_texture.loadFromFile("res\\testtexture2.jpg");
    Walls wall(wall_texture);


    //начало игры
    bool game = false;
    bool highscore = false;

    Event event;
    coord now{ g_FIELD_WIDTH / 2, g_FIELD_HEIGHT / 2, 0 };
    coord change{ -1,0,0 };
    bool ask_name = true;

    while (window.isOpen())
    {   while (menu.IsActive()) {
            while (ask_name) {
                window.clear(sf::Color(190, 228, 255, 0));
                menu.AskName(window);

                Text name{ snake.GetName() , font, 2 * g_CELL };
                name.setPosition({ static_cast<float> (g_FIELD_WIDTH * g_CELL / 3),
                    static_cast<float>((g_FIELD_HEIGHT / 2 + 3) * g_CELL) });
                window.draw(name);

                while (window.pollEvent(event)) {
                    switch (event.type) {
                    case Event::KeyPressed:
                        if (event.key.code == Keyboard::Enter) {
                            ask_name = false;
                        }
                        if (event.key.code == Keyboard::BackSpace) {
                            snake.GetName().erase(snake.GetName().getSize() - 1);
                        }
                        break;
                    case Event::TextEntered:
                        if (event.text.unicode != 8) {
                            snake.GetName() += event.text.unicode;
                        }
                    }
                }
                window.display();
            }

            window.clear(sf::Color(190, 228, 255, 0));
            menu.Render(window);

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
                        switch (menu.Go()) {
                        case 0:
                            game = true;
                            break;
                        case 1:
                            highscore = true;
                            break;
                        case 2:
                            window.close();
                            break;
                        }
                    }
                    if (event.key.code == Keyboard::Escape) {
                        window.close();
                    }
                }
            }
            window.display();
        }

        while (game ) {
            
            window.clear(Color(190, 228, 255, 0));
            wall.Render(window);

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
                                game = true;
                                end = false;
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
