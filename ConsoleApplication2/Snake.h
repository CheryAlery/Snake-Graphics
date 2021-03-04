#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"


extern const int g_CELL;

class Snake
{
public:
    Snake(const std::string name, const int lenght = 1) : m_name{ name }, m_lenght{ lenght }
    {
        m_snake_texture.loadFromFile("D:\\VS\\snake.png");

        // œŒƒ”Ã¿“‹  ¿  —ƒ≈À¿“‹ »Õ»÷»¿À»«¿÷»ﬁ »À» ¡≈« œŒ¬“Œ–Œ¬

        face.setTexture(m_snake_texture);
        face.setTextureRect(sf::IntRect(0, 0, 20, 20));
        face.setOrigin(g_CELL / 2, g_CELL / 2);
        body.setTexture(m_snake_texture);
        body.setTextureRect(sf::IntRect(20, 0, 20, 20));
        body.setOrigin(g_CELL / 2, g_CELL / 2);
        tail.setTexture(m_snake_texture);
        tail.setTextureRect(sf::IntRect(40, 0, 20, 20));
        tail.setOrigin(g_CELL / 2, g_CELL / 2);


    }

    ~Snake() {
        WriteRecord();
    }

    Snake& Render(sf::RenderWindow& window);

    Snake& EatFood();

    bool Go (const float x, const float y, const int direction);

    int GetLenght() {
        return m_lenght;
    };

private:
    sf::Texture m_snake_texture;
    sf::Sprite face;
    sf::Sprite body;
    sf::Sprite tail;


    int m_lenght;
    const std::string m_name;

    std::vector<coord> snake;

    bool CanGo(const float x, const float y) const;

    void WriteRecord() {/*
        record.push_back({ m_lenght - 1 , m_name });
        sort(record.begin(), record.end());
        reverse(record.begin(), record.end());
        record.resize(record.size() - 1);*/
    }
};

