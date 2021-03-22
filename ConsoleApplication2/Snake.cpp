#include "Snake.h"

Snake& Snake::Render(sf::RenderWindow& window) {
    if (m_lenght > 1) {
        m_tail.setRotation(90 * m_snake[m_lenght - 2].direction);
        m_tail.setPosition(g_CELL * (m_snake[m_lenght - 1].x + 0.5), g_CELL * (m_snake[m_lenght - 1].y + 0.5));
    }
    window.draw(m_tail);
    for (int i = 1; i < m_lenght - 1; ++i) {
        m_body.setRotation(90 * m_snake[i].direction);
        m_body.setPosition(g_CELL * (m_snake[i].x + 0.5), g_CELL * (m_snake[i].y + 0.5));
        window.draw(m_body);
    }
    m_face.setRotation(90 * m_snake[0].direction);
    m_face.setPosition(g_CELL * (m_snake[0].x + 0.5), g_CELL * (m_snake[0].y + 0.5));
    window.draw(m_face);
    return *this;
};

Snake& Snake::EatFood() {
    ++m_lenght;
    return *this;
}

bool Snake::Go(const float x, const float y, const int direction) {
    m_snake.insert(m_snake.begin(), { x,y,direction });
    m_snake.resize(m_lenght);
    return CanGo(x, y);
};

bool Snake::CanGo(const float x, const float y) const {
    bool head = true;
    for (const auto& coord : m_snake) {
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