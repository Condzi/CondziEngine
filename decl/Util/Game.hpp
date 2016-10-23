#pragma once
#include <iostream>
#include "Managing/StateManager.hpp"
#include "Debug/Debug.hpp"

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
