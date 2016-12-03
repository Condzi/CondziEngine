#include "Demo/CollisionDetectorComponent.hpp"

void demo::CollisionDetector::update(float deltaTime)
{
	std::vector<ce::Entity*> simulators;
	ce::EntityHolder& entityHolder = *this->GetEntityAttachedTo()->GetEntityHolderAttachedTo();
	ce::Entity* tempEntity = nullptr;
	sf::FloatRect rectA;
	sf::FloatRect rectB;
	sf::Vector2f velocityA;
	sf::Vector2f velocityB;

	for (unsigned i = 0; i < entityHolder.GetSize(); ++i)
	{
		*tempEntity = entityHolder[i];

		if (tempEntity->HasComponent< SimpleCollider >())
		{
			entityHolder[i].GetComponent< SimpleCollider >()->m_colided = false;
			simulators.push_back(&entityHolder[i]);
		}
	}

	for (unsigned i = 0; i < simulators.size(); ++i)
		for (unsigned j = simulators.size() - 1; j >= 0; ++j)
		{
			if(i == j)
				continue;

			rectA = simulators[i]->GetComponent<SimpleCollider>()->GetRect();
			rectB = simulators[j]->GetComponent<SimpleCollider>()->GetRect();

			if (simulators[i]->HasComponent<Velocity>())
			{
				velocityA = simulators[i]->GetComponent<Velocity>()->GetVelocity();

				rectA.left += velocityA.x * deltaTime;
				rectA.top += velocityA.y * deltaTime;
			}

			if (simulators[j]->HasComponent<Velocity>())
			{
				velocityB = simulators[j]->GetComponent<Velocity>()->GetVelocity();

				rectB.left += velocityB.x * deltaTime;
				rectB.top += velocityB.y * deltaTime;
			}

			if (rectA.intersects(rectB))
			{
				simulators[i]->GetComponent<SimpleCollider>()->m_colided = true;
				simulators[j]->GetComponent<SimpleCollider>()->m_colided = true;
			}
		}
}

demo::CollisionDetector::CollisionDetector()
{
}
