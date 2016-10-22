#pragma once
#include "Managing/StateManager.hpp"

namespace ce
{
	class Game
	{
	public:
		Game();

		void Run();

	private:
		sf::RenderWindow m_window;
		StateManager m_stateManager;
	};
}
