#pragma once
#include "Engine/Entity/Entity.hpp"
#include "Engine/Managing/ResourceCache.hpp"
#include "Engine/Assert.hpp"

namespace demo
{
	namespace EntityFactory
	{		
		namespace internal
		{
			static ce::ResourceCache * ResourceCachePtr = nullptr;
		}

		// Makes car (player) entity
		ce::Entity * MakeCar();
		// Makes obstacle entity
		// In future: (ObstacleType type)
		ce::Entity * MakeObstacle();
		// Makes terrain entity
		ce::Entity * MakeTerrain();
		// Makes background entity
		ce::Entity * MakeBackground();
		// Makes collision detector
		ce::Entity * MakeCollisionDetector();

		// Sets pointer to resource cache to work with
		void SetResourceCachePointer(ce::ResourceCache * resourceCache);
	}
}