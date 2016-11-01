#include "Engine/Util/Game.hpp"

ce::Game::Game(sf::Vector2u screenSize, const std::string & title, unsigned framerateLimit)
{
	m_window.create(sf::VideoMode(screenSize.x, screenSize.y), title, sf::Style::Close);
	m_window.setFramerateLimit(framerateLimit);
}

void ce::Game::AddState(unsigned short id, State * state)
{
	m_stateMachine.AddState(id, state);
	state->SetWindowPointer(&m_window);
}


void ce::Game::Run()
{	
	Logger::LogToBoth("\n=====\nStarting Game\n=====", Logger::MessageType::Info);

	m_stateMachine.Run();
	m_window.close();

	Logger::LogToBoth("\n=====\nClosing Game\n=====", Logger::MessageType::Info);
}
