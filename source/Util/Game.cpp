#include "Util/Game.hpp"

ce::Game::Game()
{
	m_window.create(sf::VideoMode(1280, 720), "Condzi Engine", sf::Style::Close);
	m_window.setFramerateLimit(48);
}

void ce::Game::Run()
{
	m_stateManager.Run();
	m_window.close();
}
