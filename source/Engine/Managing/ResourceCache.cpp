#include "Engine/Managing/ResourceCache.hpp"

void ce::ResourceCache::loadTextures(std::string & configFilePath)
{
	ConfigFile cfg;
	bool logErrors = false;

#ifdef DEBUG_LOG
	logErrors = true;
#endif // DEBUG_LOG

	std::string tempName;
	sf::Texture temporaryTexture;
	std::map< std::string, sf::Texture > tempTextures;

	if (!cfg.LoadFromFile(configFilePath, false) &&
		logErrors)
	{
		Logger::LogToFile("ResourceCache: Cannot -open- .config file with -textures- paths!");
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		Logger::LogToFile("ResourceCache: Cannot -parse- .config file with -textures- paths!");
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData(counter);

		++counter;

		if (!temporaryTexture.loadFromFile(cfg.GetData(counter)) &&
			logErrors)
		{
			Logger::LogToFile("ResourceCache: " + tempName + " - " + cfg.GetData(counter) + " - cannot -load texture-!");
		}

		tempTextures[tempName] = temporaryTexture;
	}

	m_textures = tempTextures;
}

void ce::ResourceCache::loadFonts(std::string & configFilePath)
{
	ConfigFile cfg;
	bool logErrors = false;

#ifdef DEBUG_LOG
	logErrors = true;
#endif // DEBUG_LOG	

	std::string tempName;
	sf::Font temporaryFont;
	std::map< std::string, sf::Font > tempFonts;

	if (!cfg.LoadFromFile(configFilePath, false) &&
		logErrors)
	{
		Logger::LogToFile("ResourceCache: Cannot -open- .config file with -fonts- paths!");
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		Logger::LogToFile("ResourceCache: Cannot -parse- .config file with -fonts- paths!");
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData(counter);

		++counter;

		if (!temporaryFont.loadFromFile(cfg.GetData(counter)) &&
			logErrors)
		{
			Logger::LogToFile("ResourceCache: " + tempName + " - " + cfg.GetData(counter) + " - cannot -load font-!");
		}

		tempFonts[tempName] = temporaryFont;
	}
	
	m_fonts = tempFonts;
}

void ce::ResourceCache::loadSoundBuffers(std::string & configFilePath)
{
	ConfigFile cfg;
	bool logErrors = false;

#ifdef DEBUG_LOG
	logErrors = true;
#endif // DEBUG_LOG		

	std::string tempName;
	sf::SoundBuffer temporarySoundBuffer;
	std::map< std::string, sf::SoundBuffer > tempSoundBuffers;

	if (!cfg.LoadFromFile(configFilePath, false) &&
		logErrors)
	{
		Logger::LogToFile("ResourceCache: Cannot -open- .config file with -sounds- paths!");
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		Logger::LogToFile("ResourceCache: Cannot -parse- .config file with -sounds- paths!");
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData(counter);

		++counter;

		if (!temporarySoundBuffer.loadFromFile(cfg.GetData(counter)) &&
			logErrors)
		{
			Logger::LogToFile("ResourceCache: " + tempName + " - " + cfg.GetData(counter) + " - cannot -load sound-!");
		}

		tempSoundBuffers[tempName] = temporarySoundBuffer;
	}

	m_soundBuffers = tempSoundBuffers;
}

ce::ResourceCache::ResourceCache(const std::string & configFilePath)
{
	ConfigFile cfg;
	bool logErrors = false;
	
#ifdef DEBUG_LOG
	logErrors = true;
#endif // DEBUG_LOG		

	if (!cfg.LoadFromFile(configFilePath, false) &&
		logErrors)
	{
		Logger::LogToFile("ResourceCache: Cannot -open- .config file with -resources config- paths!");
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		Logger::LogToFile("ResourceCache: Cannot -parse- .config file with -resources config- paths!");
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

	Logger::LogToFile("ResourceCache: Cannot -get (find)- sound bufer " + key + "!");
	return m_templateSoundBuffer;
}
