#include "Engine/Managing/State.hpp"

void ce::State::onActivation()
{
}

void ce::State::onDeactivation()
{
}

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
	CE_ASSERT(window, "trying to set nullptr for window in state");
	m_window = window;
}

short ce::State::Run()
{
	CE_ASSERT(m_window, "window is nullptr, window pointer not set");
	// This value doesn't matter because State::Run() should be called in 
	// Child class
	return -1;
}
