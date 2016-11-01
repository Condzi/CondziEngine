#pragma once
#include <iostream>
#include "Engine/Managing/StateMachine.hpp"
#include "Engine/Assert.hpp"

namespace ce
{
	// Main class
	class Game
	{
	public:
		// Game class constructor (not default)
		// screenSize		- size of the screen
		// title			- title of the window
		// framerateLimit	- framerate limit (0 - unlimited, not recommended)
		// All the following can be changed by state itself, so it is recommended for every state to set up window
		Game(sf::Vector2u screenSize, const std::string & title, unsigned framerateLimit);

		// Adds states to Game.
		// id		- state id (preferred to be enum, 0 is starting state)
		// state	- pointer to object inherited from ce::State
		void AddState(unsigned short id, State * state);
		// Runs Game.
		void Run();

	private:
		sf::RenderWindow m_window;
		StateMachine m_stateMachine;
	};
}
