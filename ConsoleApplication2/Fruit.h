#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Header.h"

extern const int g_FIELD_WIDTH;
extern const int g_FIELD_HEIGHT;
extern const unsigned int g_CELL;

class Fruit {
public:

    // подать на вход вектор текстур
    Fruit(sf::Texture& texture) : m_fruits_texture{texture},
        m_rasberry{ m_fruits_texture ,sf::IntRect(0, 0, 20, 20) },
        m_watermelon{ m_fruits_texture ,sf::IntRect(20, 0, 20, 20) },
        m_orange{ m_fruits_texture ,sf::IntRect(40, 0, 20, 20) }
    {
        CreateFruit();
    }

    // создает фрукт в поле с заданной шириной и высотой
    Fruit& CreateFruit();
    Fruit& Render(sf::RenderWindow& window);

    float Getx();
    float Gety();
    int GetFruit();

private:
    sf::Texture m_fruits_texture;
    sf::Sprite m_rasberry;
    sf::Sprite m_watermelon;
    sf::Sprite m_orange;
    coord m_fruit;
    int random = 0;
    int Random(const int max);
};

