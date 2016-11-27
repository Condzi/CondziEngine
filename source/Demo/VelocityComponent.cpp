#include "Demo/VelocityComponent.hpp"

void demo::Velocity::update(float deltaTime)
{
	this->GetEntityAttachedTo()->GetPositionRef() += m_velocity * deltaTime;
}

demo::Velocity::Velocity()
{
	m_velocity = sf::Vector2f(0, 0);
}

sf::Vector2f demo::Velocity::GetVelocity()
{
	return m_velocity;
}

void demo::Velocity::SetVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

void demo::Velocity::AddForce(sf::Vector2f force)
{
	m_velocity += force;
}
