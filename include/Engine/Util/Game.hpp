#pragma once
#include "Engine/Managing/StateMachine.hpp"
#include <iostream>

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

		// Add State to Game class StateMachine with specified id
		// Usage: game.AddState< MenuState >((int)StateEnums::MenuState, "resrc/menu.config")
		// id						- id of state (0 is stating state) (cannot be the same as added previous)
		// resourceCachePath		- path to resource cache
		template<class T>
		inline void ce::Game::AddState(unsigned short id, const std::string & resourceCachePath)
		{
			m_stateMachine.AddState<T>(id, resourceCachePath);
			m_stateMachine.m_states[id]->SetWindowPointer(&m_window);
		}
		// Runs Game.
		void Run();

	private:
		sf::RenderWindow m_window;
		StateMachine m_stateMachine;
	};
}
