#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

namespace ce
{
	class State
	{
	public:
		State(sf::RenderWindow & window);

		// Returns -1 to exit or state id to switch
		virtual short Run() = 0;

	protected:
		sf::RenderWindow * m_window;
		unsigned short m_id;
	};
}
