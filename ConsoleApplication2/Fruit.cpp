#include "Fruit.h"


Fruit& Fruit::CreateFruit() {
    do {
        m_fruit.x = 1 + static_cast<float>(Random(m_field_width));
        m_fruit.y = 1 + static_cast<float>(Random(m_field_height));
        m_fruit.direction = Random(3);
    } while (false);//Walls::Get()[fruit_coord]);
    return *this;
}

Fruit& Fruit::Render(sf::RenderWindow& window) {
    if (GetFruit() == 0) {
        orange.setPosition(m_cell * Getx(), m_cell * Gety());
        window.draw(orange);
    }
    if (GetFruit() == 1) {
        rasberry.setPosition(m_cell * Getx(), m_cell * Gety());
        window.draw(rasberry);
    }
    if (GetFruit() == 2) {
        watermelon.setPosition(m_cell * Getx(), m_cell * Gety());
        window.draw(watermelon);
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