#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Header.h"



class Fruit {
public:
    Fruit(int field_width, int field_height,int cell=20) :
        m_field_width{ field_width - 2},
        m_field_height{ field_height - 2 }, m_cell{cell} {
        m_fruits_texture.loadFromFile("D:\\VS\\fruits.png");

        // ÏÎÄÓÌÀÒÜ ÊÀÊ ÑÄÅËÀÒÜ ÈÍÈÖÈÀËÈÇÀÖÈŞ ÈËÈ ÁÅÇ ÏÎÂÒÎĞÎÂ

        rasberry.setTexture(m_fruits_texture);
        rasberry.setTextureRect(sf::IntRect(0, 0, 20, 20));       
        watermelon.setTexture(m_fruits_texture);
        watermelon.setTextureRect(sf::IntRect(20, 0, 20, 20));
        orange.setTexture(m_fruits_texture);
        orange.setTextureRect(sf::IntRect(40, 0, 20, 20));

        CreateFruit();

    }

    // ñîçäàåò ôğóêò â ïîëå ñ çàäàííîé øèğèíîé è âûñîòîé
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
    const int m_cell;
    const int m_field_width;
    const int m_field_height;
    int random = 0;
    int Random(const int max);
};

