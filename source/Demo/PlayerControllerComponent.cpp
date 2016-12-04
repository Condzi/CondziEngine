#include "Demo/PlayerControllerComponent.hpp"

void demo::PlayerController::update(float deltaTime)
{
	sf::Vector2f force = sf::Vector2f(0,0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		force.x = -m_movementForce.x;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		force.x = m_movementForce.x;


	this->m_entityAttachedTo->GetPositionRef() += force * deltaTime;
}

demo::PlayerController::PlayerController()
{
	m_movementForce = sf::Vector2f(0, 0);
}

sf::Vector2f demo::PlayerController::GetMovementForce()
{
	return m_movementForce;
}

void demo::PlayerController::SetMovementForce(sf::Vector2f movementForce)
{
	m_movementForce = movementForce;
}

void demo::PlayerController::AddForce(sf::Vector2f force)
{
	m_movementForce += force;
}
