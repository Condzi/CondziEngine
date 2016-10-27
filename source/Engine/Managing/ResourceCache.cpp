#include "Engine/Managing/ResourceCache.hpp"

void ce::ResourceCache::loadTextures(std::string & configFilePath)
{
	ConfigFile cfg;

	std::string tempName;
	sf::Texture temporaryTexture;
	std::map< std::string, sf::Texture > tempTextures;

	if (!cfg.LoadFromFile(configFilePath, false))
	{
		Logger::LogToFile("ResourceCache: Cannot -open- .config file with -textures- paths!");
		
		return;
	}

	if (!cfg.Parse())
	{
		Logger::LogToFile("ResourceCache: Cannot -parse- .config file with -textures- paths!");
		
		return;
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData("name" + std::to_string(counter));

		if (!temporaryTexture.loadFromFile(cfg.GetData("path" + std::to_string(counter))))
		{
			Logger::LogToFile("ResourceCache: " + tempName + " - " + cfg.GetData("path" + std::to_string(counter)) + " - cannot -load texture-!");
		
			continue;
		}

		tempTextures[tempName] = temporaryTexture;
	}

	m_textures = tempTextures;
}

void ce::ResourceCache::loadFonts(std::string & configFilePath)
{
	ConfigFile cfg;

	std::string tempName;
	sf::Font temporaryFont;
	std::map< std::string, sf::Font > tempFonts;

	if (!cfg.LoadFromFile(configFilePath, false))
	{
		Logger::LogToFile("ResourceCache: Cannot -open- .config file with -textures- paths!");
		
		return;
	}

	if (!cfg.Parse())
	{
		Logger::LogToFile("ResourceCache: Cannot -parse- .config file with -textures- paths!");

		return;
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData("name" + std::to_string(counter));

		if (!temporaryFont.loadFromFile(cfg.GetData("path" + std::to_string(counter))))
		{
			Logger::LogToFile("ResourceCache: " + tempName + " - " + cfg.GetData("path" + std::to_string(counter)) + " - cannot -load font-!");
			
			continue;
		}

		tempFonts[tempName] = temporaryFont;
	}
	
	m_fonts = tempFonts;
}

void ce::ResourceCache::loadSoundBuffers(std::string & configFilePath)
{
	ConfigFile cfg;

	std::string tempName;
	sf::SoundBuffer temporarySoundBuffer;
	std::map< std::string, sf::SoundBuffer > tempSoundBuffers;

	if (!cfg.LoadFromFile(configFilePath, false))
	{		
		Logger::LogToFile("ResourceCache: Cannot -open- .config file with -textures- paths!");
		
		return;
	}

	if (!cfg.Parse())
	{
		Logger::LogToFile("ResourceCache: Cannot -parse- .config file with -textures- paths!");
		
		return;
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData("name" + std::to_string(counter));

		if (!temporarySoundBuffer.loadFromFile(cfg.GetData("path" + std::to_string(counter))))
		{
			Logger::LogToFile("ResourceCache: " + tempName + " - " + cfg.GetData("path" + std::to_string(counter)) + " - cannot -load sound-!");
		
			continue;
		}

		tempSoundBuffers[tempName] = temporarySoundBuffer;
	}

	m_soundBuffers = tempSoundBuffers;
}

ce::ResourceCache::ResourceCache(const std::string & configFilePath)
{
	ConfigFile cfg;
	
	if (!configFilePath.size())
	{
		Logger::LogToFile("ResourceCache: No config file path");
		
		return;
	}

	if (!cfg.LoadFromFile(configFilePath, false))
	{
		Logger::LogToFile("ResourceCache: Cannot -open- .config file with -resources config- paths!");
	
		return;
	}

	if (!cfg.Parse())
	{
		Logger::LogToFile("ResourceCache: Cannot -parse- .config file with -resources config- paths!");
		
		return;
	}

	loadTextures(cfg.GetData("TEXTURES"));
	loadFonts(cfg.GetData("FONTS"));
	loadSoundBuffers(cfg.GetData("SOUNDBUFFERS"));
}

const sf::Texture & ce::ResourceCache::GetTexture(const std::string & key)
{
	for (auto it = m_textures.begin(); it != m_textures.end(); ++it)
	{
		if (it->first == key)
		{
			return m_textures[key];
		}
	}

	Logger::LogToFile("ResourceCache: Cannot -get (find)- texture " + key + "!");
	
	return m_templateTexture;
}

const sf::Font & ce::ResourceCache::GetFont(const std::string & key)
{
	for (auto it = m_fonts.begin(); it != m_fonts.end(); ++it)
	{
		if (it->first == key)
		{
			return m_fonts[key];
		}
	}

	Logger::LogToFile("ResourceCache: Cannot -get (find)- font " + key + "!");
	
	return m_templateFont;
}

const sf::SoundBuffer & ce::ResourceCache::GetSoundBuffer(const std::string & key)
{
	for (auto it = m_soundBuffers.begin(); it != m_soundBuffers.end(); ++it)
	{
		if (it->first == key)
		{
			return m_soundBuffers[key];
		}
	}

	Logger::LogToFile("ResourceCache: Cannot -get (find)- sound buffer " + key + "!");
	
	return m_templateSoundBuffer;
}
