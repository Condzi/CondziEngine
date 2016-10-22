#include "Managing/State.hpp"

ce::State::State(sf::RenderWindow & window, const std::string & resourceManagerConfig)
{
	m_window = &window;
	m_resourceManager = new ResourceManager(resourceManagerConfig);
}
