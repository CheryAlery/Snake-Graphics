#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"


extern const unsigned int g_CELL;

class Snake
{
public:
    Snake(sf::Texture& texture, const sf::String name = "", const int lenght = 1) : 
        m_name{ name }, 
        m_lenght{ lenght },
        m_snake_texture{texture},
        m_face { m_snake_texture, sf::IntRect(0, 0, 20, 20)},
        m_body { m_snake_texture, sf::IntRect(20, 0, 20, 20)},
        m_tail { m_snake_texture, sf::IntRect(40, 0, 20, 20)}
    {    
        m_face.setOrigin(g_CELL / 2, g_CELL / 2);
        m_body.setOrigin(g_CELL / 2, g_CELL / 2);
        m_tail.setOrigin(g_CELL / 2, g_CELL / 2);
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

    sf::String& GetName() {
        return m_name;
    }

private:
    sf::Texture m_snake_texture;
    sf::Sprite m_face;
    sf::Sprite m_body;
    sf::Sprite m_tail;
    sf::String m_name;

    int m_lenght;

    std::vector<coord> m_snake;

    bool CanGo(const float x, const float y) const;

    void WriteRecord() {/*
        record.push_back({ m_lenght - 1 , m_name });
        sort(record.begin(), record.end());
        reverse(record.begin(), record.end());
        record.resize(record.size() - 1);*/
    }
};

