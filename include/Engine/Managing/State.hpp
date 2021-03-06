#pragma once
#include "Engine/Assert.hpp"
#include "Engine/Entity/EntityHolder.hpp"
#include "Engine/Managing/ResourceCache.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace ce
{
	// Virtual class State
	// Inherit from it if you want to create State for Game
	// Methods to override:
	// void onActivation()
	// void onDeactivation()
	// **** MUST TO OVERRIDE
	// short Run()
	class State
	{
		friend class StateMachine;

	private:
		virtual void onActivation();
		virtual void onDeactivation();

	public:
		// State constructor (not default)
		// resourceCacheConfig - path to cfg file with paths to textures, fonts...
		// If configPath = "" then nothing is trying to load
		State(const std::string & resourceCacheConfig);
		virtual ~State();

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
