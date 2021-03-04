#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Header.h"

extern const int g_FIELD_WIDTH;
extern const int g_FIELD_HEIGHT;
extern const int g_CELL;

class Fruit {
public:

    // подать на вход вектор текстур
    Fruit() {
        m_fruits_texture.loadFromFile("D:\\VS\\fruits.png");

        // ПОДУМАТЬ КАК СДЕЛАТЬ ИНИЦИАЛИЗАЦИЮ ИЛИ БЕЗ ПОВТОРОВ

        rasberry.setTexture(m_fruits_texture);
        rasberry.setTextureRect(sf::IntRect(0, 0, 20, 20));       
        watermelon.setTexture(m_fruits_texture);
        watermelon.setTextureRect(sf::IntRect(20, 0, 20, 20));
        orange.setTexture(m_fruits_texture);
        orange.setTextureRect(sf::IntRect(40, 0, 20, 20));
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
    sf::Sprite rasberry;
    sf::Sprite watermelon;
    sf::Sprite orange;
    coord m_fruit;
    int random = 0;
    int Random(const int max);
};

