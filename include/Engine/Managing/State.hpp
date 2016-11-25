#pragma once
#include "Engine/Assert.hpp"
#include "Engine/Entity/EntityHolder.hpp"
#include "Engine/Managing/ResourceCache.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace ce
{
	// Virtual class Sate
	// Inherit from it if you want to create State for Game
	class State
	{
	public:
		// State constructor (not default)
		// resourceCacheConfig - path to cfg file with paths to textures, fonts...
		// If configPath = "" then nothing is trying to load
		State(const std::string & resourceCacheConfig);
		~State();

		// Sets window pointer 
		// window - pointer to sf::RenderWindow
		void SetWindowPointer(sf::RenderWindow * window);
		// It is recommended to call this->State::Run() before everything in CustomState::Run()
		// Runs state
		// Returns -1 to exit or state id to switch
		virtual short Run();

	protected:
		sf::RenderWindow * m_window;
		EntityHolder m_entityHolder;

		ResourceCache * m_resourceCache;
	};
}
