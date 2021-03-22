#include "Fruit.h"


Fruit& Fruit::CreateFruit() {
    do {
        m_fruit.x = 1 + static_cast<float>(Random(g_FIELD_WIDTH-2));
        m_fruit.y = 1 + static_cast<float>(Random(g_FIELD_HEIGHT-2));
        m_fruit.direction = Random(3);
    } while (false);//Walls::Get()[fruit_coord]);
    return *this;
}

Fruit& Fruit::Render(sf::RenderWindow& window) {
    if (GetFruit() == 0) {
        m_orange.setPosition(g_CELL * Getx(), g_CELL * Gety());
        window.draw(m_orange);
    }
    if (GetFruit() == 1) {
        m_rasberry.setPosition(g_CELL * Getx(), g_CELL * Gety());
        window.draw(m_rasberry);
    }
    if (GetFruit() == 2) {
        m_watermelon.setPosition(g_CELL * Getx(), g_CELL * Gety());
        window.draw(m_watermelon);
    }
    return *this;
};


float Fruit::Getx() {
    return m_fruit.x;
};
float Fruit::Gety() {
    return m_fruit.y;
};
int Fruit::GetFruit() {
    return m_fruit.direction;
};

int Fruit::Random(const int max) {
    srand(time(0) + random); // автоматическая рандомизация
    random = rand() % (max);
    return random;
}