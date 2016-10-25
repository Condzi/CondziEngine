#include "Engine/Managing/State.hpp"

ce::State::State(const std::string & resourceCacheConfig)
{
	m_window = nullptr;
	m_resourceCache = new ResourceCache(resourceCacheConfig);
}

ce::State::~State()
{
	delete m_resourceCache;
}

void ce::State::SetWindowPointer(sf::RenderWindow * window)
{
	m_window = window;
}

short ce::State::Run()
{
	if (m_window == nullptr)
	{
		ce::Logger::LogToFile("State: m_window is nullptr!");
		return -1;
	}
}
