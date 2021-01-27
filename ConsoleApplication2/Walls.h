#pragma once
#include <vector>
#include "Header.h"
#include <SFML/Graphics.hpp>

class Walls
{
public:
    // получает длину и ширину поля, рисует его.
    Walls(const int width, const int height, const int cell) :
        m_width {width}, m_height {height}, m_cell{cell} ,
        field {sf::Vector2f((width - 2) * cell, (height - 2) * cell)}
    {
        wall_texture.setRepeated(true);
        wall_texture.loadFromFile("D:\\VS\\testtexture2.jpg");
        wall.setTexture(wall_texture);
        wall.setTextureRect(sf::IntRect(0, 0, m_width* m_cell, m_cell));
        field.move(m_cell, m_cell);
        field.setFillColor(sf::Color(025, 075, 025));
    };

    // создаем горизонтальное препятствие в заданных коориднатах
    Walls& CreateHorizontalWall(const int length, const float x, const float y);
   
    // создаем вертикальное препятствие в заданных коориднатах
    Walls& CreateVerticalWall(const int length, const float x, const float y);

    // СОЗДАТЬ СПРАЙТ ДЛЯ БАРЬЕРА И ДОБАВИТЬ В ФУНКЦИЮ РЕНДЕР БАРЬЕРОВ
    void Render(sf::RenderWindow& window);

    bool Here(float x, float y) {
        if (abs(x) < 0.1 || abs(x - m_width + 1 ) < 0.1 || abs(y) < 0.1 || abs(y - m_height + 1) < 0.1) {
            return true;
        }
        if (!wall_coord.empty()) {
            for (coord wall : wall_coord) {
                if ((abs(x - wall.x) < 0.1 && abs(y - wall.y) < 0.1)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    sf::Texture wall_texture;
    const int m_cell;
    const int m_width;
    const int m_height;
    std::vector<coord> wall_coord;
    sf::Sprite wall;
    sf::RectangleShape field;

};


