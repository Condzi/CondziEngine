#pragma once
#include "Engine/Managing/State.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Demo/States.hpp"
#include "Demo/EntityFactory.hpp"

namespace demo
{
	class PlayState :
		public ce::State
	{
	private:
		// Create entities
		void onActivation();
		// Remove entities
		void onDeactivation();

	public:
		PlayState(const std::string & resourceCachePath);

		short Run();
	};
}