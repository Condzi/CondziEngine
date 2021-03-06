#pragma once
#include "Engine/ConfigFileReader/ConfigFile.hpp"
#include "Engine/Logger/Logger.hpp"
#include <map>
#include <fstream>

namespace ce
{
	// Resource Cache for custom resource
	// It must have method "bool LoadFromFile(path)" !
	template<class T>
	class CustomResourceCache
	{
	private:
		bool load(const std::string & configFilePath);

	public:
		// Custom Resource Cache constructor (not default)
		// cfgFile	- path to config file
		// tag		- tag that it looks for in config file
		CustomResourceCache(const std::string & cfgFile, const std::string & tag);

		// Returns tag that it looks for in config file
		std::string GetTag();

		// Sets tag
		// tag - tag that it looks for in config file
		void SetTag(const std::string & tag);
		// Sets config file path
		// cfgFile - path to config file
		void SetConfigFilePath(const std::string & cfgFile);

		// You probably don't need this method... 
		// *You should load EVERYTHING from config files!*
		// resource - resource
		// key - resource name
		// returns reference to resource
		T * Add(const T & resource, const std::string & key);
		// Reloads resources 
		// returns false if failed
		bool Reload();
		// Returns reference to resource
		// If cannot find returns placeholder
		// key - resource name
		T * Get(const std::string & key);

	private:
		std::string m_configFile;
		std::string m_tag;
	
		std::map< std::string, T > m_resources;
	};

}

#include "CustomResourceCache.inl"