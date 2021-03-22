#pragma once
#include <vector>
#include "Header.h"
#include <SFML/Graphics.hpp>


extern const int g_FIELD_WIDTH;
extern const int g_FIELD_HEIGHT;
extern const unsigned int g_CELL;

class Walls
{
public:
    // получает длину и ширину поля, рисует его.
    Walls(sf::Texture& texture) : 
        m_wall_texture{texture},
        m_wall{m_wall_texture,sf::IntRect(0, 0, g_FIELD_WIDTH * g_CELL, g_CELL)},
        m_field{ { sf::Vector2f((g_FIELD_WIDTH - 2) * g_CELL, (g_FIELD_HEIGHT - 2) * g_CELL) } }
    {   m_wall_texture.setRepeated(true);
        m_field.move(g_CELL, g_CELL);
        m_field.setFillColor(sf::Color(025, 075, 025));
    };

    // создаем горизонтальное препятствие в заданных коориднатах
    Walls& CreateHorizontalWall(const int length, const float x, const float y);
   
    // создаем вертикальное препятствие в заданных коориднатах
    Walls& CreateVerticalWall(const int length, const float x, const float y);

    // СОЗДАТЬ СПРАЙТ ДЛЯ БАРЬЕРА И ДОБАВИТЬ В ФУНКЦИЮ РЕНДЕР БАРЬЕРОВ
    void Render(sf::RenderWindow& window);

    bool Here(float x, float y);

private:
    sf::Texture m_wall_texture;
    std::vector<coord> wall_coord;
    sf::Sprite m_wall;
    sf::RectangleShape m_field;

};


