#include "Engine/Util/Game.hpp"

ce::Game::Game()
{
	m_window.create(sf::VideoMode(1280, 720), "Condzi Engine", sf::Style::Close);
	m_window.setFramerateLimit(48);
}


void ce::Game::Run()
{
	PlayState ps(m_window, "resources/playState.config");
	m_stateMachine.AddSate(1, &ps);
	
	m_stateMachine.Run();
	m_window.close();
}
