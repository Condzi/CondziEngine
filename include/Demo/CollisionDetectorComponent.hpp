#pragma once
#include "Engine/Entity/EntityHolder.hpp"
#include "Demo/SimpleColliderComponent.hpp"
#include "Demo/VelocityComponent.hpp"

namespace demo
{
	class CollisionDetector :
		public ce::Component
	{
	private:
		void update(float deltaTime);

	public:
		CollisionDetector();

	};
}