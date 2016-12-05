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

ce::DrawableComponent::DrawableComponent()
{
}

void ce::UpdateabaleComponent::update(float)
{
}

ce::UpdateabaleComponent::UpdateabaleComponent()
{
}

void ce::Component::update(float)
{
}

void ce::Component::draw(sf::RenderTarget &, sf::RenderStates) const
{
}

ce::Component::Component()
{
}
