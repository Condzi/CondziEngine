#include "Engine/Util/Game.hpp"

ce::Game::Game()
{
	m_window.create(sf::VideoMode(1280, 720), "Conine", sf::Style::Close);
	m_window.setFramerateLimit(48);
}

void ce::Game::AddState(unsigned short id, State * state)
{
	state->SetWindowPointer(&m_window);
	m_stateMachine.AddState(id, state);
}


void ce::Game::Run()
{	
	m_stateMachine.Run();
	m_window.close();
}
