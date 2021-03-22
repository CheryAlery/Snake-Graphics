#pragma once
#include <SFML/Graphics.hpp>

extern const int g_FIELD_WIDTH;
extern const int g_FIELD_HEIGHT;
extern const int g_TABLE_WIDTH;
extern const unsigned int g_CELL;

class Menu
{public:
	Menu(sf::Font& font) : 
		m_font{ font },
		m_title{ "SNAKE", m_font, 3 * g_CELL },
		m_play{ "Play", m_font, 2 * g_CELL },
		m_high("High Score", m_font, 2 * g_CELL),
		m_exit{ "Exit", m_font, 2 * g_CELL },
		m_get_name{ "Your name:", m_font, 2 * g_CELL } {
	m_title.setFillColor(sf::Color(0, 78, 0));
	m_get_name.setFillColor(sf::Color(0, 0, 0));
	m_title.setPosition({ static_cast<float> ((g_FIELD_WIDTH + g_TABLE_WIDTH)* g_CELL / 3),
		static_cast<float>( (g_FIELD_HEIGHT / 2 - 6)* g_CELL )});
	m_play.setPosition({ static_cast<float> (g_FIELD_WIDTH * g_CELL / 3),
		static_cast<float> ((g_FIELD_HEIGHT / 2) * g_CELL) });
	m_high.setPosition({ static_cast<float> (g_FIELD_WIDTH * g_CELL / 3),
		static_cast<float> ((g_FIELD_HEIGHT / 2 + 3) * g_CELL )});
	m_exit.setPosition({ static_cast<float> (g_FIELD_WIDTH * g_CELL / 3),
		static_cast<float> ((g_FIELD_HEIGHT / 2 + 6) * g_CELL) });
	m_get_name.setPosition({ static_cast<float> (g_FIELD_WIDTH * g_CELL / 3),
		static_cast<float>((g_FIELD_HEIGHT / 2) * g_CELL) });
	ClearColor();
	Color();
	}

	Menu& Render(sf::RenderWindow& window);

	Menu& AskName(sf::RenderWindow& window) {
		window.draw(m_title);
		window.draw(m_get_name);
		return *this;
	}

	bool IsActive() {
		return menu_active;
	}

	Menu& Up();

	Menu& Down();

	int Go();

	Menu& Activate();

private:

	Menu& ClearColor();

	Menu& Color();

	bool menu_active = true;
	sf::Text m_title;
	sf::Text m_play;
	sf::Text m_high;
	sf::Text m_exit;
	sf::Text m_get_name;
	sf::Font m_font;
	int m_active_bottom {
	};
};

