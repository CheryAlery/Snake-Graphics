#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"

class Snake
{
public:
    Snake(const std::string name, const int cell, const int lenght = 1) : m_name{ name }, m_cell{ cell }, m_lenght{ lenght }
    {
        m_snake_texture.loadFromFile("D:\\VS\\snake.png");

        // ÏÎÄÓÌÀÒÜ ÊÀÊ ÑÄÅËÀÒÜ ÈÍÈÖÈÀËÈÇÀÖÈÞ ÈËÈ ÁÅÇ ÏÎÂÒÎÐÎÂ

        face.setTexture(m_snake_texture);
        face.setTextureRect(sf::IntRect(0, 0, 20, 20));
        face.setOrigin(m_cell / 2, m_cell / 2);
        body.setTexture(m_snake_texture);
        body.setTextureRect(sf::IntRect(20, 0, 20, 20));
        body.setOrigin(m_cell / 2, m_cell / 2);
        tail.setTexture(m_snake_texture);
        tail.setTextureRect(sf::IntRect(40, 0, 20, 20));
        tail.setOrigin(m_cell / 2, m_cell / 2);


    }

    ~Snake() {
        WriteRecord();
    }

    Snake& Render(sf::RenderWindow& window) {
        if (m_lenght > 1) {
            tail.setRotation(90 * snake[m_lenght - 2].direction);
            tail.setPosition(m_cell * (snake[m_lenght - 1].x + 0.5), m_cell * (snake[m_lenght - 1].y + 0.5));
        }
        window.draw(tail);
        for (int i = 1; i < m_lenght - 1; ++i) {
            body.setRotation(90 * snake[i].direction);
            body.setPosition(m_cell * (snake[i].x + 0.5), m_cell * (snake[i].y + 0.5));
            window.draw(body);
        }
        face.setRotation(90 * snake[0].direction);
        face.setPosition(m_cell * (snake[0].x + 0.5), m_cell * (snake[0].y + 0.5));
        window.draw(face);
        return *this;
    };

    Snake& EatFood(){
        ++m_lenght;
    return *this;};

    bool Go (const float x, const float y, const int direction) {
        snake.insert(snake.begin(), { x,y,direction });
        snake.resize(m_lenght);
        return CanGo(x, y);
    };

    int GetLenght() {
        return m_lenght;
    };

private:
    sf::Texture m_snake_texture;
    sf::Sprite face;
    sf::Sprite body;
    sf::Sprite tail;


    int m_lenght;
    const int m_cell;
    const std::string m_name;

    std::vector<coord> snake;

    bool CanGo(const float x, const float y) const {
        bool head = true;
        for (const auto& coord : snake) {
            if (head) {
                head = false;
                continue;
            }
            if ((abs(x - coord.x) < 0.1 && abs(y - coord.y) < 0.1)) {
                return false;
            }
        }
        return true;
    };

    void WriteRecord() {/*
        record.push_back({ m_lenght - 1 , m_name });
        sort(record.begin(), record.end());
        reverse(record.begin(), record.end());
        record.resize(record.size() - 1);*/
    }
};

