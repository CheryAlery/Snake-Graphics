#pragma once
#include <vector>
#include "Header.h"
#include <SFML/Graphics.hpp>


extern const int g_FIELD_WIDTH;
extern const int g_FIELD_HEIGHT;
extern const int g_CELL;

class Walls
{
public:
    // �������� ����� � ������ ����, ������ ���.
    Walls()
    {
        wall_texture.setRepeated(true);
        wall_texture.loadFromFile("D:\\VS\\testtexture2.jpg");
        wall.setTexture(wall_texture);
        wall.setTextureRect(sf::IntRect(0, 0, g_FIELD_WIDTH* g_CELL, g_CELL));
        field.move(g_CELL, g_CELL);
        field.setFillColor(sf::Color(025, 075, 025));
    };

    // ������� �������������� ����������� � �������� �����������
    Walls& CreateHorizontalWall(const int length, const float x, const float y);
   
    // ������� ������������ ����������� � �������� �����������
    Walls& CreateVerticalWall(const int length, const float x, const float y);

    // ������� ������ ��� ������� � �������� � ������� ������ ��������
    void Render(sf::RenderWindow& window);

    bool Here(float x, float y);

private:
    sf::Texture wall_texture;
    std::vector<coord> wall_coord;
    sf::Sprite wall;
    sf::RectangleShape field{ sf::Vector2f((g_FIELD_WIDTH - 2) * g_CELL, (g_FIELD_HEIGHT - 2) * g_CELL) };

};


