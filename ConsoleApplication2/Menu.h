#pragma once
#include <SFML/Graphics.hpp>


extern const int g_FIELD_WIDTH;
extern const int g_FIELD_HEIGHT;
extern const int g_TABLE_WIDTH;
extern const int g_CELL;

class Menu
{public:
	Menu(sf::Font font) : 
		m_font{ font },
		m_title{ "SNAKE", m_font, 3 * g_CELL },
		m_play{ "Play", m_font, 2 * g_CELL },
		m_high("High Score", m_font, 2 * g_CELL),
		m_exit{ "Exit", m_font, 2 * g_CELL } {
	m_title.setFillColor(sf::Color(0, 78, 0));
	m_title.setPosition({ static_cast<float> ((g_FIELD_WIDTH + g_TABLE_WIDTH)* g_CELL / 3),static_cast<float>( (g_FIELD_HEIGHT / 2 - 6)* g_CELL )});
	m_play.setPosition({ static_cast<float> (g_FIELD_WIDTH * g_CELL / 3), static_cast<float> ((g_FIELD_HEIGHT / 2) * g_CELL) });
	m_high.setPosition({ static_cast<float> (g_FIELD_WIDTH * g_CELL / 3), static_cast<float> ((g_FIELD_HEIGHT / 2 + 3) * g_CELL )});
	m_exit.setPosition({ static_cast<float> (g_FIELD_WIDTH * g_CELL / 3), static_cast<float> ((g_FIELD_HEIGHT / 2 + 6) * g_CELL) });
	ClearColor();
	Color();
	}

	Menu& Render(sf::RenderWindow& window) {
		window.draw(m_title);
		window.draw(m_play);
		window.draw(m_high);
		window.draw(m_exit);
		return *this;
	};

	bool IsActive() {
		return active;
	}


	Menu& Up() {
		ClearColor();
		active_bottom = (active_bottom + 2) % 3;
		Color();
		return *this;
	}

	Menu& Down() {
		ClearColor();
		active_bottom = (active_bottom + 1) % 3;
		Color();
		return *this;
	}

	int Go() {
		active = false;
		return active_bottom;
	}

	Menu& Activate() {
		active = true;
		return *this;
	}

private:

	Menu& ClearColor() {
		m_play.setFillColor(sf::Color(0, 0, 0));
		m_high.setFillColor(sf::Color(0, 0, 0));
		m_exit.setFillColor(sf::Color(0, 0, 0));
		return *this;
	}

	Menu& Color() {
		switch (active_bottom) {
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


	bool active = true;
	sf::Text m_title;
	sf::Text m_play;
	sf::Text m_high;
	sf::Text m_exit;
	sf::Font m_font;
	int active_bottom {
	};
};

