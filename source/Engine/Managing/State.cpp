#include "Engine/Managing/State.hpp"

ce::State::State(sf::RenderWindow & window, const std::string & resourceCacheConfig)
{
	m_window = &window;
	m_resourceCache = new ResourceCache(resourceCacheConfig);
}

ce::State::~State()
{
	delete m_resourceCache;
}
