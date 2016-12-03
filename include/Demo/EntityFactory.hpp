#pragma once
#include "Engine/Entity/Entity.hpp"
#include "Engine/Managing/ResourceCache.hpp"
#include "Engine/Assert.hpp"
#include "Demo/CollisionDetectorComponent.hpp"
#include "Demo/PlayerControllerComponent.hpp"
#include "Demo/SimpleColliderComponent.hpp"
#include "Demo/SpriteRendererComponent.hpp"
#include "Demo/VelocityComponent.hpp"

namespace demo
{
	namespace EntityFactory
	{		
		namespace internal
		{
			static ce::ResourceCache * ResourceCachePtr = nullptr;
		}

		// Makes car (player) entity
		ce::Entity * MakeCar(ce::Entity * entity);
		// Makes obstacle entity
		// In future: (ObstacleType type)
		ce::Entity * MakeObstacle(ce::Entity * entity);
		// Makes terrain entity
		ce::Entity * MakeTerrain(ce::Entity * entity);
		// Makes background entity
		ce::Entity * MakeBackground(ce::Entity * entity);
		// Makes collision detector
		ce::Entity * MakeCollisionDetector(ce::Entity * entity);

		// Sets pointer to resource cache to work with
		void SetResourceCachePointer(ce::ResourceCache * resourceCache);
	}
}