#include "Engine/Managing/NewResourceCache.hpp"

template<typename Resource>
ce::NewResourceCache<Resource>::NewResourceCache()
{
}

template<typename Resource>
Resource * ce::NewResourceCache<Resource>::GetResource(const std::string & name)
{
	if (m_resources.find(name) == m_resources.end())
	{
		Logger::Log("ResourceCache: Cannot find '" + name + "'", Logger::MessageType::Error, Logger::Output::All);
		
		return nullptr;
	}

	return &m_resources[name];
}

template<typename Resource>
Resource * ce::NewResourceCache<Resource>::AddResource(Resource * r, const std::string & name)
{
	if (m_resources.find(name) != m_resources.end())
	{
		Logger::Log("ResourceCache: Find same resource name '" + name "', overwriting", Logger::MessageType::Warning, Logger::Output::All);
		m_resources[name] = r;
		
		return m_resources[name];
	}

	return nullptr;
}

template<typename Resource>
void ce::NewResourceCache<Resource>::DeleteResource(const std::string & name)
{
	if (m_resources.find(name) == m_resources.end())
	{
		Logger::Log("ResourceCache: [deleting] Cannot find '" + name + "'", Logger::MessageType::Error, Logger::Output::All);
		
		return;
	}

	m_resources[name].release(nullptr);
	m_resources.erase(name);
}

template<typename Resource>
void ce::NewResourceCache<Resource>::DeleteAll()
{
	for (std::shared_ptr<Resource> r : m_resources)
	{
		r->release();
	}

	m_resources.clear();
}
