#include "Engine/Util/Game.hpp"

ce::Game::Game(sf::Vector2u screenSize, const std::string & title, unsigned framerateLimit)
{
	m_window.create(sf::VideoMode(screenSize.x, screenSize.y), title, sf::Style::Close);
	m_window.setFramerateLimit(framerateLimit);
}

void ce::Game::Run()
{	
	Logger::Log("\n=====\nStarting Game\n=====", Logger::MessageType::Info, Logger::Output::All);

	m_stateMachine.Run();
	m_window.close();

	Logger::Log("\n=====\nClosing Game\n=====", Logger::MessageType::Info, Logger::Output::All);
}
