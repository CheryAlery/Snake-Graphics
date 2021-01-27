#include "Walls.h"

Walls& Walls::CreateHorizontalWall(const int length, const float x, const float y) {
    for (int i = 0; i <= length; ++i) {
        wall_coord.push_back({ x + static_cast<float>(i), y });
    }
    return *this;
};

Walls& Walls::CreateVerticalWall(const int length, const float x, const float y) {
    for (int i = 0; i <= length; ++i) {
        wall_coord.push_back({ x, y + i });
    }
    return *this;
};

void Walls::Render(sf::RenderWindow& window) {
    wall.setPosition(0.f, 0.f);
    wall.setRotation(0.f);
    window.draw(wall);
    wall.move(0.f, (m_width - 1) * m_cell);
    window.draw(wall);
    wall.setRotation(90.f);
    wall.setPosition(m_cell, m_cell);
    window.draw(wall);
    wall.move((m_width - 1) * m_cell, 0.f);
    window.draw(wall);
    window.draw(field);
};

