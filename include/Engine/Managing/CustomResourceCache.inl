#pragma once
#include "CustomResourceCache.hpp"

template<class T>
inline bool ce::CustomResourceCache<T>::load(const std::string & configFilePath)
{
	if (configFilePath == "@none")
	{
		Logger::Log("CustomResourceCache: no path", Logger::MessageType::Warning, Logger::Output::All);

		return false;
	}

	ConfigFile cfg;

	std::string tempName;
	T temporaryRes;

	if (!cfg.LoadFromFile(configFilePath, false))
	{
		Logger::Log("CustomResourceCache: Cannot -open- .config file with paths!", Logger::MessageType::Error, Logger::Output::All);

		return false;
	}

	if (!cfg.Parse())
	{
		Logger::Log("CustomResourceCache: Cannot -parse- .config file with paths!", Logger::MessageType::Error, Logger::Output::All);

		return false;
	}

	if (cfg.GetAmountOfData() % 2)
	{
		Logger::Log("CustomResourceCache: .config with -custom resource- have odd number of data (no name or path?)", Logger::MessageType::Error, Logger::Output::All);

		return false;
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData() / 2; ++counter)
	{
		tempName = cfg.GetData("name" + std::to_string(counter));

		if (!temporaryRes.LoadFromFile(cfg.GetData("path" + std::to_string(counter))))
		{
			Logger::Log("CustomResourceCache: " + tempName + " - " + cfg.GetData("path" + std::to_string(counter)) + " - cannot -load custom resource-!", Logger::MessageType::Error, Logger::Output::All);

			continue;
		}

		m_resources[tempName].LoadFromFile(cfg.GetData("path" + std::to_string(counter)));
	}

	return true;
}

template<class T>
inline ce::CustomResourceCache<T>::CustomResourceCache(const std::string & cfgFile, const std::string & tag)
{
	m_configFile = cfgFile;
	m_tag = tag;
}

template<class T>
inline std::string ce::CustomResourceCache<T>::GetTag()
{
	return m_tag;
}

template<class T>
inline void ce::CustomResourceCache<T>::SetTag(const std::string & tag)
{
	m_tag = tag;
}

template<class T>
inline void ce::CustomResourceCache<T>::SetConfigFilePath(const std::string & cfgFile)
{
	m_configFile = cfgFile;
}

template<class T>
inline T * ce::CustomResourceCache<T>::Add(const T & resource, const std::string & key)
{
	if(m_resources.find(key) != m_resources.end())
	{
		Logger::Log("CustomResourceCache: find same name of resource '" + key + "', overwriting", Logger::MessageType::Warning, Logger::Output::All);
	}

	m_resources[key] = resource;
	
	return &m_resources[key];
}

template<class T>
inline bool ce::CustomResourceCache<T>::Reload()
{
	ConfigFile cfg;

	if (!m_configFile.size())
	{
		Logger::Log("CustomResourceCache: no -config file- path", Logger::MessageType::Warning, Logger::Output::All);

		return false;
	}

	if (!cfg.LoadFromFile(m_configFile, false))
	{
		Logger::Log("CustomResourceCache: Cannot -open- .config file with -resources config- paths!", Logger::MessageType::Error, Logger::Output::All);

		return false;
	}

	if (!cfg.Parse())
	{
		Logger::Log("CustomResourceCache: Cannot -parse- .config file with -resources config- paths!", Logger::MessageType::Error, Logger::Output::All);

		return false;
	}

	return load(cfg.GetData(m_tag));
}

template<class T>
inline T * ce::CustomResourceCache<T>::Get(const std::string & key)
{
	if (m_resources.find(key) == m_resources.end())
	{
		Logger::Log("CustomResourceCache: Cannot find '" + key + "'", Logger::MessageType::Error, Logger::Output::All);	
	
		return nullptr
	}

	return &m_resources[key];
}
