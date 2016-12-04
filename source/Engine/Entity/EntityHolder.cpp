#include "Engine/Entity/EntityHolder.hpp"

void ce::EntityHolder::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto & e : m_entities)
		target.draw(e, states);
}

ce::EntityHolder::EntityHolder()
{
}

bool ce::EntityHolder::HasEntity(const std::string & name)
{
	for (auto & e : m_entities)
		if (e.m_name == name)
			return true;

	return false;
}

ce::Entity * ce::EntityHolder::GetEntity(const std::string & name)
{
	for (auto & e : m_entities)
		if (e.m_name == name)
			return &e;

	Logger::Log("EntityHolder: Cannot get, cannot find Entity '" + name + "'", Logger::MessageType::Error, Logger::Output::All);

	return nullptr;
}

ce::Entity * ce::EntityHolder::GetEntity(unsigned int id)
{
	for (auto & e : m_entities)
		if (e.m_id == id)
			return &e;

	return nullptr;
}

ce::Entity * ce::EntityHolder::AddEntity()
{
	m_entities.push_back(ce::Entity());

	m_entities.back().m_holderAttachedTo = this;

	return &m_entities.back();
}

bool ce::EntityHolder::RemoveEntity(const std::string & name)
{
	for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
		if (it->m_name == name)
		{
			m_entities.erase(it);

			return true;
		}

	Logger::Log("EntityHolder: Cannot remove, cannot find Entity '" + name + "'", Logger::MessageType::Error, Logger::Output::All);

	return false;
}

void ce::EntityHolder::RemoveAll()
{
	Logger::Log("EntityHolder: Removed " + std::to_string(m_entities.size()) + " Entities", ce::Logger::MessageType::Info, ce::Logger::Output::All);
	
	m_entities.clear();
}

void ce::EntityHolder::SleepAll()
{
	for (auto & c : m_entities)
		c.Sleep();
}

void ce::EntityHolder::InvokeAll()
{
	for (auto & c : m_entities)
		c.Invoke();
}

void ce::EntityHolder::UpdateAll(float deltaTime)
{
	for (auto & c : m_entities)
		c.Update(deltaTime);
}

ce::Entity & ce::EntityHolder::operator[](unsigned int index)
{
	return m_entities[index];
}

unsigned int ce::EntityHolder::GetSize()
{
	return m_entities.size();
}