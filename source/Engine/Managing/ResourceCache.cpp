#include "Engine/Managing/ResourceCache.hpp"

void ce::ResourceCache::loadTextures(std::string & configFilePath)
{
	if (configFilePath == "@none")
	{
		Logger::Log("ResourceCache: no -textures- path", Logger::MessageType::Warning, Logger::Output::All);

		return;
	}

	ConfigFile cfg;

	std::string tempName;
	sf::Texture temporaryTexture;
	std::map< std::string, sf::Texture > tempTextures;

	if (!cfg.LoadFromFile(configFilePath, false))
	{
		Logger::Log("ResourceCache: Cannot -open- .config file with -textures- paths!", Logger::MessageType::Warning, Logger::Output::All);
		
		return;
	}

	if (!cfg.Parse())
	{
		Logger::Log("ResourceCache: Cannot -parse- .config file with -textures- paths!", Logger::MessageType::Error, Logger::Output::All);
		
		return;
	}

	if (cfg.GetAmountOfData() % 2)
	{
		Logger::Log("ResourceCache: .config with -textures- have odd number of data (no name or path?)", Logger::MessageType::Error, Logger::Output::All);
		
		return;
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData() / 2; ++counter)
	{
		tempName = cfg.GetData("name" + std::to_string(counter));

		if (!temporaryTexture.loadFromFile(cfg.GetData("path" + std::to_string(counter))))
		{
			Logger::Log("ResourceCache: " + tempName + " - " + cfg.GetData("path" + std::to_string(counter)) + " - cannot -load texture-!", Logger::MessageType::Error, Logger::Output::All);
		
			continue;
		}

		tempTextures[tempName] = temporaryTexture;
	}

	m_textures = tempTextures;
}

void ce::ResourceCache::loadFonts(std::string & configFilePath)
{
	if (configFilePath == "@none")
	{
		Logger::Log("ResourceCache: no -fonts- path", Logger::MessageType::Warning, Logger::Output::All);

		return;
	}

	ConfigFile cfg;

	std::string tempName;
	sf::Font temporaryFont;
	std::map< std::string, sf::Font > tempFonts;

	if (!cfg.LoadFromFile(configFilePath, false))
	{
		Logger::Log("ResourceCache: Cannot -open- .config file with -fonts- paths!", Logger::MessageType::Error, Logger::Output::All);
		
		return;
	}

	if (!cfg.Parse())
	{
		Logger::Log("ResourceCache: Cannot -parse- .config file with -fonts- paths!", Logger::MessageType::Error, Logger::Output::All);

		return;
	}

	if (cfg.GetAmountOfData() % 2)
	{
		Logger::Log("ResourceCache: .config with -fonts- have odd number of data (no name or path?)", Logger::MessageType::Error, Logger::Output::All);

		return;
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData() / 2; ++counter)
	{
		tempName = cfg.GetData("name" + std::to_string(counter));

		if (!temporaryFont.loadFromFile(cfg.GetData("path" + std::to_string(counter))))
		{
			Logger::Log("ResourceCache: " + tempName + " - " + cfg.GetData("path" + std::to_string(counter)) + " - cannot -load font-!", Logger::MessageType::Error,Logger::Output::All);
			
			continue;
		}

		tempFonts[tempName] = temporaryFont;
	}
	
	m_fonts = tempFonts;
}

void ce::ResourceCache::loadSoundBuffers(std::string & configFilePath)
{
	if (configFilePath == "@none")
	{
		Logger::Log("ResourceCache: no -sound buffers- path", Logger::MessageType::Warning, Logger::Output::All);

		return;
	}

	ConfigFile cfg;

	std::string tempName;
	sf::SoundBuffer temporarySoundBuffer;
	std::map< std::string, sf::SoundBuffer > tempSoundBuffers;

	if (!cfg.LoadFromFile(configFilePath, false))
	{		
		Logger::Log("ResourceCache: Cannot -open- .config file with -sound buffers- paths!", Logger::MessageType::Error, Logger::Output::All);
		
		return;
	}

	if (!cfg.Parse())
	{
		Logger::Log("ResourceCache: Cannot -parse- .config file with -sound buffers- paths!", Logger::MessageType::Error, Logger::Output::All);
		
		return;
	}

	if (cfg.GetAmountOfData() % 2)
	{
		Logger::Log("ResourceCache: .config with -sound buffers- have odd number of data (no name or path?)", Logger::MessageType::Error, Logger::Output::All);

		return;
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData() / 2; ++counter)
	{
		tempName = cfg.GetData("name" + std::to_string(counter));

		if (!temporarySoundBuffer.loadFromFile(cfg.GetData("path" + std::to_string(counter))))
		{
			Logger::Log("ResourceCache: " + tempName + " - " + cfg.GetData("path" + std::to_string(counter)) + " - cannot -load sound-!", Logger::MessageType::Error, Logger::Output::All);
		
			continue;
		}

		tempSoundBuffers[tempName] = temporarySoundBuffer;
	}

	m_soundBuffers = tempSoundBuffers;
}

void ce::ResourceCache::loadMusic(std::string & configFilePath)
{
	if (configFilePath == "@none")
	{
		Logger::Log("ResourceCache: no -musics- path", Logger::MessageType::Warning, Logger::Output::All);

		return;
	}

	ConfigFile cfg;

	std::string tempName;
	sf::Music temporaryMusic;

	if (!cfg.LoadFromFile(configFilePath, false))
	{
		Logger::Log("ResourceCache: Cannot -open- .config file with -musics- paths!", Logger::MessageType::Error, Logger::Output::All);

		return;
	}

	if (!cfg.Parse())
	{
		Logger::Log("ResourceCache: Cannot -parse- .config file with -musics- paths!", Logger::MessageType::Error, Logger::Output::All);

		return;
	}

	if (cfg.GetAmountOfData() % 2)
	{
		Logger::Log("ResourceCache: .config with -musics- have odd number of data (no name or path?)", Logger::MessageType::Error, Logger::Output::All);

		return;
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData() / 2; ++counter)
	{
		tempName = cfg.GetData("name" + std::to_string(counter));

		if (!temporaryMusic.openFromFile(cfg.GetData("path" + std::to_string(counter))))
		{
			Logger::Log("ResourceCache: " + tempName + " - " + cfg.GetData("path" + std::to_string(counter)) + " - cannot -load music-!", Logger::MessageType::Error, Logger::Output::All);

			continue;
		}

		m_music[tempName].openFromFile(cfg.GetData("path" + std::to_string(counter)));
	}
}

ce::ResourceCache::ResourceCache(const std::string & configFilePath)
{
	ConfigFile cfg;
	
	if (!configFilePath.size())
	{
		Logger::Log("ResourceCache: no -config file- path", Logger::MessageType::Warning, Logger::Output::All);
		
		return;
	}

	if (!cfg.LoadFromFile(configFilePath, false))
	{
		Logger::Log("ResourceCache: Cannot -open- .config file with -resources config- paths!", Logger::MessageType::Error, Logger::Output::All);
	
		return;
	}

	if (!cfg.Parse())
	{
		Logger::Log("ResourceCache: Cannot -parse- .config file with -resources config- paths!", Logger::MessageType::Error, Logger::Output::All);
		
		return;
	}

	loadTextures(cfg.GetData("TEXTURES"));
	loadFonts(cfg.GetData("FONTS"));
	loadSoundBuffers(cfg.GetData("SOUNDBUFFERS"));
	loadMusic(cfg.GetData("MUSIC"));
}

sf::Texture * ce::ResourceCache::GetTexture(const std::string & key)
{
	for (auto it = m_textures.begin(); it != m_textures.end(); ++it)
	{
		if (it->first == key)
		{
			return &m_textures[key];
		}
	}

	Logger::Log("ResourceCache: Cannot -get (find)- texture " + key + "!", Logger::MessageType::Warning, Logger::Output::All);
	
	return nullptr;
}

sf::Font * ce::ResourceCache::GetFont(const std::string & key)
{
	for (auto it = m_fonts.begin(); it != m_fonts.end(); ++it)
	{
		if (it->first == key)
		{
			return &m_fonts[key];
		}
	}

	Logger::Log("ResourceCache: Cannot -get (find)- font " + key + "!", Logger::MessageType::Warning, Logger::Output::All);
	
	return nullptr;
}

sf::SoundBuffer * ce::ResourceCache::GetSoundBuffer(const std::string & key)
{
	for (auto it = m_soundBuffers.begin(); it != m_soundBuffers.end(); ++it)
	{
		if (it->first == key)
		{
			return &m_soundBuffers[key];
		}
	}

	Logger::Log("ResourceCache: Cannot -get (find)- sound buffer " + key + "!", Logger::MessageType::Warning, Logger::Output::All);
	
	return nullptr;
}

sf::Music * ce::ResourceCache::GetMusic(const std::string & key)
{
	for (auto it = m_music.begin(); it != m_music.end(); ++it)
	{
		if (it->first == key)
		{
			return &m_music[key];
		}
	}

	Logger::Log("ResourceCache: Cannot -get (find)- music " + key + "!", Logger::MessageType::Warning, Logger::Output::All);

	return nullptr;
}
