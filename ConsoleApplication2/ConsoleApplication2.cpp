#include <SFML/Graphics.hpp>
#include "Header.h"
#include "Fruit.h"
#include "Walls.h"
#include "Snake.h"

using namespace sf;

int main()
{// cglazhivanie
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    setlocale(LC_ALL, "rus");

    const int FIELD_WIDTH = 25;
    const int FIELD_HEIGHT = 25;
    const int TABLE_WIDTH = 10;
    const int CELL = 20;

    RenderWindow window(sf::VideoMode((FIELD_WIDTH + TABLE_WIDTH) * CELL
        , FIELD_HEIGHT * CELL), "Snake");

    // TODO сделать размер отношением 20/CELL;


    Fruit fruit(FIELD_WIDTH, FIELD_HEIGHT, CELL);
    Walls wall(FIELD_WIDTH, FIELD_HEIGHT, CELL);

    bool menu = true;

    Font font;
    font.loadFromFile("D:\VS\\snake_font.otf");

    Text title("SNAKE", font, 3 *CELL);
    Text pl("Play", font, 2 * CELL);
    Text high("High Score", font, 2 * CELL);
    Text exit("Exit", font, 2 * CELL);
    title.setFillColor(Color(0, 78, 0));
    title.setPosition({ (FIELD_WIDTH + TABLE_WIDTH) * CELL/3, (FIELD_HEIGHT / 2 - 6) * CELL });
    pl.setPosition({ FIELD_WIDTH * CELL/3, (FIELD_HEIGHT / 2 ) * CELL });
    high.setPosition({ FIELD_WIDTH * CELL/3, (FIELD_HEIGHT / 2 + 3) * CELL });
    exit.setPosition({ FIELD_WIDTH * CELL/3, (FIELD_HEIGHT / 2 + 6) * CELL });


    while (window.isOpen())
    {
        while (menu) {
            window.clear(Color(190, 228, 255, 0));
            Event event;

            window.draw(title);
            window.draw(pl);
            window.draw(high);
            window.draw(exit);
           
            while (window.pollEvent(event))
            {   if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::P) {
                        menu = false;
                    }
                    else if (event.key.code == Keyboard::H) {

                    }
                    else if (event.key.code == Keyboard::Escape) {
                        window.close();
                    }
                }
            }
            window.display();
        }
        //стены
        bool play = true;

        float x = FIELD_WIDTH / 2;
        float y = FIELD_HEIGHT / 2;
        float dx = 0;
        float dy = 0;
        int direction = 0;

        Snake snake("name", CELL);
        while (play) {

            window.clear(Color(190, 228, 255, 0));
            wall.Render(window);
            sf::Event event;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Up) {
                        dy = -1;
                        dx = 0;
                        direction = 1;
                    }
                    else if (event.key.code == Keyboard::Down) {
                        dy = +1;
                        dx = 0;
                        direction = 3;
                    }
                    else if (event.key.code == Keyboard::Left) {
                        dx = -1;
                        dy = 0;
                        direction = 0;
                    }
                    else if (event.key.code == Keyboard::Right) {
                        dx = +1;
                        dy = 0;
                        direction = 2;
                    }
                }
            }

            x += dx;
            y += dy;

            if (!snake.Go(x, y, direction) || wall.Here(x,y)) {
                Text text("You died, again?\n Y/N", font, 2 * CELL);
                text.setPosition({ 2 * CELL, (FIELD_HEIGHT / 2 - 6) * CELL });
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
                                play = false;
                            }
                            else if (event.key.code == Keyboard::N) {
                                menu = true;
                                play = false;
                                end = false;
                            }
                        }
                    }
                }
            };

            snake.Render(window);

            if (abs(x - fruit.Getx()) < 0.1 && abs(y - fruit.Gety()) < 0.1) {
                snake.EatFood();
                fruit.CreateFruit();
            }
            fruit.Render(window);

            window.display();
            Time stop = seconds(0.5f);
            sleep(stop);
        }
    }

    return 0;
}
