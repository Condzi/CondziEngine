#include "Engine/Entity/Component.hpp"

void ce::BasicComponent::onCreate()
{
}

void ce::BasicComponent::onDelete()
{
}

void ce::BasicComponent::onSleep()
{
}

void ce::BasicComponent::onInvoke()
{
}

ce::BasicComponent::BasicComponent()
{
	m_entityAttachedTo = nullptr;
}

ce::Entity * ce::BasicComponent::GetEntityAttachedTo()
{
	return m_entityAttachedTo;
}

void ce::DrawableComponent::draw(sf::RenderTarget &, sf::RenderStates) const
{
}

void ce::UpdatebaleComponent::update(float)
{
}

ce::UpdatebaleComponent::UpdatebaleComponent()
{
}

ce::Component::Component()
{
}
