#pragma once
#include <iostream>
#include "Engine/Managing/StateMachine.hpp"
#include "Pong/States/PlayState.hpp"
#include "Engine/Debug/Debug.hpp"

namespace ce
{
	// Add states before running!
	class Game
	{
	public:
		Game();

		void Run();

	private:
		sf::RenderWindow m_window;
		StateMachine m_stateMachine;
	};
}
