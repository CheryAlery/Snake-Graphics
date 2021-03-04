#include "Snake.h"

Snake& Snake::Render(sf::RenderWindow& window) {
    if (m_lenght > 1) {
        tail.setRotation(90 * snake[m_lenght - 2].direction);
        tail.setPosition(g_CELL * (snake[m_lenght - 1].x + 0.5), g_CELL * (snake[m_lenght - 1].y + 0.5));
    }
    window.draw(tail);
    for (int i = 1; i < m_lenght - 1; ++i) {
        body.setRotation(90 * snake[i].direction);
        body.setPosition(g_CELL * (snake[i].x + 0.5), g_CELL * (snake[i].y + 0.5));
        window.draw(body);
    }
    face.setRotation(90 * snake[0].direction);
    face.setPosition(g_CELL * (snake[0].x + 0.5), g_CELL * (snake[0].y + 0.5));
    window.draw(face);
    return *this;
};

Snake& Snake::EatFood() {
    ++m_lenght;
    return *this;
}

bool Snake::Go(const float x, const float y, const int direction) {
    snake.insert(snake.begin(), { x,y,direction });
    snake.resize(m_lenght);
    return CanGo(x, y);
};

bool Snake::CanGo(const float x, const float y) const {
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