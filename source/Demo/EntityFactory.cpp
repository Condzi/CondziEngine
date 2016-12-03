#include "Demo/EntityFactory.hpp"

ce::Entity * demo::EntityFactory::MakeCar(ce::Entity * entity)
{
	entity->RemoveAllComponents();

	entity->AddComponent< PlayerController >()->SetMovementForce(sf::Vector2f(100, 0));
	entity->AddComponent< SpriteRenderer >()->SetTexture(&internal::ResourceCachePtr->GetTexture("Player"));
	entity->AddComponent< SimpleCollider >()->SetRect(entity->GetComponent< SpriteRenderer >()->GetRect());

	return entity;
}

ce::Entity * demo::EntityFactory::MakeObstacle(ce::Entity * entity)
{
	entity->RemoveAllComponents();

	entity->AddComponent< SpriteRenderer >()->SetTexture(&internal::ResourceCachePtr->GetTexture("Obstacle"));
	entity->AddComponent< SimpleCollider >()->SetRect(entity->GetComponent< SpriteRenderer >()->GetRect());
	entity->AddComponent< Velocity >()->SetVelocity(sf::Vector2f(-100, 0));

	return entity;
}

ce::Entity * demo::EntityFactory::MakeTerrain(ce::Entity * entity)
{
	entity->RemoveAllComponents();

	entity->AddComponent< SpriteRenderer >()->SetTexture(&internal::ResourceCachePtr->GetTexture("Background"));
	
	return entity;
}

ce::Entity * demo::EntityFactory::MakeCollisionDetector(ce::Entity * entity)
{
	entity->RemoveAllComponents();

	entity->AddComponent< CollisionDetector >();

	return entity;
}

void demo::EntityFactory::SetResourceCachePointer(ce::ResourceCache * resourceCache)
{
	//CE_ASSERT(resourceCache, "cannot be nullptr");
	
	internal::ResourceCachePtr = resourceCache;
}
