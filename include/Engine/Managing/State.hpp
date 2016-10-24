#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Engine/Managing/ResourceCache.hpp"

namespace ce
{
	class State
	{
	public:
		State(sf::RenderWindow & window, const std::string & resourceCacheConfig);
		~State();

		// Returns -1 to exit or state id to switch
		virtual short Run() = 0;

	protected:
		sf::RenderWindow * m_window;

		ResourceCache * m_resourceCache;
	};
}
