#pragma once
#include "Engine/Entity/Component.hpp"
#include "Engine/Entity/Entity.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace demo
{
	// Player Controller 
	// Add it if you want to move Entity
	class PlayerController :
		public ce::Component
	{
	private:
		void update(float deltaTime);

	public:
		PlayerController();

		sf::Vector2f GetMovementForce();

		void SetMovementForce(sf::Vector2f movementForce);
		void AddForce(sf::Vector2f force);

	private:
		sf::Vector2f m_movementForce;
	};
}