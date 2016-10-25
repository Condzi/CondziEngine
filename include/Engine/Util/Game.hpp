#pragma once
#include <iostream>
#include "Engine/Managing/StateMachine.hpp"
#include "Pong/States/PlayState.hpp"
#include "Engine/Logger/Logger.hpp"

namespace ce
{
	// Add states before running!
	class Game
	{
	public:
		Game();
		void AddState(unsigned short id, State * state);
		void Run();

	private:
		sf::RenderWindow m_window;
		StateMachine m_stateMachine;
	};
}
