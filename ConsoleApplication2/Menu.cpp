#include "Menu.h"

Menu& Menu::Render(sf::RenderWindow& window) {
	window.draw(m_title);
	window.draw(m_play);
	window.draw(m_high);
	window.draw(m_exit);
	return *this;
};

Menu& Menu::Up() {
	ClearColor();
	m_active_bottom = (m_active_bottom + 2) % 3;
	Color();
	return *this;
}

Menu& Menu::Down() {
	ClearColor();
	m_active_bottom = (m_active_bottom + 1) % 3;
	Color();
	return *this;
}

int Menu::Go() {
	menu_active = false;
	return m_active_bottom;
}

Menu& Menu::Activate() {
	menu_active = true;
	return *this;
}

Menu& Menu::ClearColor() {
	m_play.setFillColor(sf::Color(0, 0, 0));
	m_high.setFillColor(sf::Color(0, 0, 0));
	m_exit.setFillColor(sf::Color(0, 0, 0));
	return *this;
}

Menu& Menu::Color() {
	switch (m_active_bottom) {
	case 0:
		m_play.setFillColor(sf::Color(200, 0, 0));
		break;
	case 1:
		m_high.setFillColor(sf::Color(200, 0, 0));
		break;
	case 2:
		m_exit.setFillColor(sf::Color(200, 0, 0));
		break;
	}
	return *this;
}
