#include "Demo/SimpleColliderComponent.hpp"

void demo::SimpleCollider::update(float deltaTime)
{
	m_bounds.left += this->GetEntityAttachedTo()->GetPosition().x + m_localPosition.x;
	m_bounds.top += this->GetEntityAttachedTo()->GetPosition().y + m_localPosition.y;
}

demo::SimpleCollider::SimpleCollider()
{
	m_bounds = sf::FloatRect(0, 0, 0, 0);
	m_localPosition = sf::Vector2f(0, 0);
}

void demo::SimpleCollider::SetSize(sf::Vector2f size)
{
	m_bounds.width = size.x;
	m_bounds.height = size.y;
}

void demo::SimpleCollider::SetLocalPosition(sf::Vector2f position)
{
	m_localPosition = position;
}

void demo::SimpleCollider::SetRect(const sf::FloatRect & rect)
{
	m_bounds = rect;
}

sf::FloatRect demo::SimpleCollider::GetRect()
{
	return m_bounds;
}

bool demo::SimpleCollider::IsCollision()
{
	return m_colided;
}
