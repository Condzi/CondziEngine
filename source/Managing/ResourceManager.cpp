#include "Managing/ResourceManager.hpp"

void ce::ResourceManager::loadTextures(std::string & configFilePath)
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
		Logger::LogToFile("ResourceManager: Cannot -open- .config file with -textures- paths!");
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		Logger::LogToFile("ResourceManager: Cannot -parse- .config file with -textures- paths!");
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData(counter);

		++counter;

		if (!temporaryTexture.loadFromFile(cfg.GetData(counter)) &&
			logErrors)
		{
			Logger::LogToFile("ResourceManager: " + tempName + " - " + cfg.GetData(counter) + " - cannot -load texture-!");
		}

		tempTextures[tempName] = temporaryTexture;
	}

	m_textures = tempTextures;
}

void ce::ResourceManager::loadFonts(std::string & configFilePath)
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
		Logger::LogToFile("ResourceManager: Cannot -open- .config file with -fonts- paths!");
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		Logger::LogToFile("ResourceManager: Cannot -parse- .config file with -fonts- paths!");
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData(counter);

		++counter;

		if (!temporaryFont.loadFromFile(cfg.GetData(counter)) &&
			logErrors)
		{
			Logger::LogToFile("ResourceManager: " + tempName + " - " + cfg.GetData(counter) + " - cannot -load font-!");
		}

		tempFonts[tempName] = temporaryFont;
	}
	
	m_fonts = tempFonts;
}

void ce::ResourceManager::loadSoundBuffers(std::string & configFilePath)
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
		Logger::LogToFile("ResourceManager: Cannot -open- .config file with -sounds- paths!");
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		Logger::LogToFile("ResourceManager: Cannot -parse- .config file with -sounds- paths!");
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData(counter);

		++counter;

		if (!temporarySoundBuffer.loadFromFile(cfg.GetData(counter)) &&
			logErrors)
		{
			Logger::LogToFile("ResourceManager: " + tempName + " - " + cfg.GetData(counter) + " - cannot -load sound-!");
		}

		tempSoundBuffers[tempName] = temporarySoundBuffer;
	}

	m_soundBuffers = tempSoundBuffers;
}

ce::ResourceManager::ResourceManager(const std::string & configFilePath)
{
	ConfigFile cfg;
	bool logErrors = false;
	
#ifdef DEBUG_LOG
	logErrors = true;
#endif // DEBUG_LOG		

	if (!cfg.LoadFromFile(configFilePath, false) &&
		logErrors)
	{
		Logger::LogToFile("ResourceManager: Cannot -open- .config file with -resources config- paths!");
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		Logger::LogToFile("ResourceManager: Cannot -parse- .config file with -resources config- paths!");
	}

	loadTextures(cfg.GetData("TEXTURES"));
	loadFonts(cfg.GetData("FONTS"));
	loadSoundBuffers(cfg.GetData("SOUNDBUFFERS"));
}

const sf::Texture & ce::ResourceManager::GetTexture(const std::string & key)
{
	for (auto it = m_textures.begin(); it != m_textures.end(); ++it)
	{
		if (it->first == key)
		{
			return m_textures[key];
		}
	}

	Logger::LogToFile("ResourceManager: Cannot -get (find)- texture " + key + "!");
	return m_templateTexture;
}

const sf::Font & ce::ResourceManager::GetFont(const std::string & key)
{
	for (auto it = m_fonts.begin(); it != m_fonts.end(); ++it)
	{
		if (it->first == key)
		{
			return m_fonts[key];
		}
	}

	Logger::LogToFile("ResourceManager: Cannot -get (find)- font " + key + "!");
	return m_templateFont;
}

const sf::SoundBuffer & ce::ResourceManager::GetSoundBuffer(const std::string & key)
{
	for (auto it = m_soundBuffers.begin(); it != m_soundBuffers.end(); ++it)
	{
		if (it->first == key)
		{
			return m_soundBuffers[key];
		}
	}

	Logger::LogToFile("ResourceManager: Cannot -get (find)- sound bufer " + key + "!");
	return m_templateSoundBuffer;
}
