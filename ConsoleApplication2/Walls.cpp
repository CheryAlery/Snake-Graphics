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
    wall.move(0.f, (g_FIELD_WIDTH - 1) * g_CELL);
    window.draw(wall);
    wall.setRotation(90.f);
    wall.setPosition(g_CELL, g_CELL);
    window.draw(wall);
    wall.move((g_FIELD_WIDTH - 1) * g_CELL, 0.f);
    window.draw(wall);
    window.draw(field);
};

bool Walls::Here(float x, float y) {
    if (abs(x) < 0.1 || abs(x - g_FIELD_WIDTH + 1) < 0.1 || abs(y) < 0.1 || abs(y - g_FIELD_HEIGHT + 1) < 0.1) {
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
};

