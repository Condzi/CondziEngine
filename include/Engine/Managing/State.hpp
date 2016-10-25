#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Engine/Managing/ResourceCache.hpp"

namespace ce
{
	class State
	{
	public:
		State(const std::string & resourceCacheConfig);
		~State();

		void SetWindowPointer(sf::RenderWindow * window);
		// Returns -1 to exit or state id to switch
		virtual short Run();

	protected:
		sf::RenderWindow * m_window;

		ResourceCache * m_resourceCache;
	};
}
