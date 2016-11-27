#pragma once
#include "Engine/Entity/Component.hpp"
#include "Engine/Entity/Entity.hpp"

namespace demo
{
	class SimpleCollider :
		public ce::Component
	{
		friend class CollisionDetector;

	private:
		void update(float deltaTime);

	public:
		SimpleCollider();

		sf::FloatRect GetBounds();
		bool IsCollision();

		void SetSize(sf::Vector2f size);
		// Sets position relative to Entity position
		void SetLocalPosition(sf::Vector2f position);

	private:
		sf::FloatRect m_bounds;
		sf::Vector2f m_localPosition;
		bool m_colided;
	};
}