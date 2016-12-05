#include "Engine/Entity/Entity.hpp"

void ce::Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto & d : m_drawable)
		target.draw(*d, states);

	for (auto & c : m_components)
		target.draw(*c, states);
}

unsigned int ce::Entity::makeID()
{
	static unsigned int counter = 0;
	return ++counter;
}


ce::Entity::Entity()
{
	m_id = makeID();
	m_name = "(Unnamed)";
	m_position = sf::Vector2f(0, 0);
	m_isSleeping = false;
	m_holderAttachedTo = nullptr;
}

ce::Entity::~Entity()
{
	for (auto & c : m_components)
		c->BasicComponent::onDelete();

	for (auto & b : m_basic)
		b->onDelete();

	for (auto & u : m_updatable)
		u->onDelete();

	for (auto & d : m_drawable)
		d->onDelete();
}

sf::Vector2f ce::Entity::GetPosition()
{
	return m_position;
}

sf::Vector2f & ce::Entity::GetPositionRef()
{
	return m_position;
}

void ce::Entity::Update(float frameTime)
{
	if (m_isSleeping)
		return;

	for (auto & u : m_updatable)
		u->update(frameTime);

	for (auto & c : m_components)
		c->update(frameTime);
}

void ce::Entity::RemoveAllComponents()
{
	m_components.clear();
	m_basic.clear();
	m_updatable.clear();
	m_drawable.clear();
}

void ce::Entity::SetName(const std::string & name)
{
	if (m_name == name)
		return;

	Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): renaming to '" + name + "'", Logger::MessageType::Info, Logger::Output::All);

	m_name = name;
}

void ce::Entity::SetPosition(const sf::Vector2f & position)
{
	m_position = position;
}

std::string ce::Entity::GetName()
{
	return m_name;
}

unsigned int ce::Entity::GetID()
{
	return m_id;
}

ce::EntityHolder * ce::Entity::GetEntityHolderAttachedTo()
{
	return m_holderAttachedTo;
}

bool ce::Entity::IsSleeping()
{
	return m_isSleeping;
}

void ce::Entity::Invoke()
{
	if (!m_isSleeping)
	{
		Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): failed to invoke, already invoke", Logger::MessageType::Warning, Logger::Output::All);
		
		return;
	}

	for (auto & c : m_components)
		c->BasicComponent::onInvoke();

	for (auto & b : m_basic)
		b->onInvoke();

	for (auto & u : m_updatable)
		u->onInvoke();

	for (auto & d : m_drawable)
		d->onInvoke();
}

void ce::Entity::Sleep()
{
	if (m_isSleeping)
	{
		Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): failed to sleep, already sleep", Logger::MessageType::Warning, Logger::Output::All);

		return;
	}

	for (auto & c : m_components)
		c->BasicComponent::onSleep();

	for (auto & b : m_basic)
		b->onSleep();

	for (auto & u : m_updatable)
		u->onSleep();

	for (auto & d : m_drawable)
		d->onSleep();
}
