#include "Engine/Entity/Component.hpp"

void ce::Component::onCreate()
{
}

void ce::Component::onDelete()
{
}

void ce::Component::onSleep()
{
}

void ce::Component::onInvoke()
{
}

void ce::Component::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
}

void ce::Component::update(float dt)
{
}

ce::Component::Component()
{
	m_entityAttachedTo = nullptr;
}

ce::Entity & ce::Component::GetEntityAttachedTo()
{
	return *m_entityAttachedTo;
}
