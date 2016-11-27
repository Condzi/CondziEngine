#pragma once
#include "Engine/Entity/Component.hpp"
#include "Engine/Entity/Entity.hpp"

namespace demo
{
	class Velocity :
		public ce::Component
	{
		friend class CollisionDetector;

	private:
		void update(float deltaTime);

	public:
		Velocity();

		// Returns velocity
		sf::Vector2f GetVelocity();
		
		// Sets velocity
		void SetVelocity(sf::Vector2f velocity);
		// Adds force to velocity
		void AddForce(sf::Vector2f force);

	private:
		sf::Vector2f m_velocity;
	};
}