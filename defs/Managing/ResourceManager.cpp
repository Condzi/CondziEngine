#include "Managing/ResourceManager.hpp"

void ce::ResourceManager::loadTextures(std::string & configFilePath, ErrorCode::ResourceManager * errCode)
{
	ConfigFile cfg;
	bool logErrors = errCode != nullptr;
	std::string tempName = "";
	sf::Texture temporaryTexture;
	std::map< std::string, sf::Texture > tempTextures;

	if (!cfg.LoadFromFile(configFilePath, false) &&
		logErrors)
	{
		*errCode = ErrorCode::ResourceManager::CFG_PATHS_TEXTURES;
		return;
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		*errCode = ErrorCode::ResourceManager::CFG_PATHS_TEXTURES_BAD_PARSED;
		return;
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData(counter);

		++counter;

		if (!temporaryTexture.loadFromFile(cfg.GetData(counter)) &&
			logErrors)
		{
			*errCode = ErrorCode::ResourceManager::LOAD_CANNOTOPEN_TEXTURE;
			return;
		}

		tempTextures[tempName] = temporaryTexture;
	}

	m_textures = tempTextures;
}

void ce::ResourceManager::loadFonts(std::string & configFilePath, ErrorCode::ResourceManager * errCode)
{
	ConfigFile cfg;
	bool logErrors = errCode != nullptr;
	std::string tempName = "";
	sf::Font temporaryFont;
	std::map< std::string, sf::Font > tempFonts;

	if (!cfg.LoadFromFile(configFilePath, false) &&
		logErrors)
	{
		*errCode = ErrorCode::ResourceManager::CFG_PATHS_FONTS;
		return;
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		*errCode = ErrorCode::ResourceManager::CFG_PATHS_FONTS_BAD_PARSED;
		return;
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData(counter);

		++counter;

		if (!temporaryFont.loadFromFile(cfg.GetData(counter)) &&
			logErrors)
		{
			*errCode = ErrorCode::ResourceManager::LOAD_CANNOTOPEN_FONT;
			return;
		}

		tempFonts[tempName] = temporaryFont;
	}
	
	m_fonts = tempFonts;
}

void ce::ResourceManager::loadSoundBuffers(std::string & configFilePath, ErrorCode::ResourceManager * errCode)
{
	ConfigFile cfg;
	bool logErrors = errCode != nullptr;
	std::string tempName = "";
	sf::SoundBuffer temporarySoundBuffer;
	std::map< std::string, sf::SoundBuffer > tempSoundBuffers;

	if (!cfg.LoadFromFile(configFilePath, false) &&
		logErrors)
	{
		*errCode = ErrorCode::ResourceManager::CFG_PATHS_SOUNDBUFFERS;
		return;
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		*errCode = ErrorCode::ResourceManager::CFG_PATHS_SOUNDBUFFERS_BAD_PARSED;
		return;
	}

	for (unsigned short counter = 0; counter < cfg.GetAmountOfData(); ++counter)
	{
		tempName = cfg.GetData(counter);

		++counter;

		if (!temporarySoundBuffer.loadFromFile(cfg.GetData(counter)) &&
			logErrors)
		{
			*errCode = ErrorCode::ResourceManager::LOAD_CANNOTOPEN_SOUNDBUFFER;
			return;
		}

		tempSoundBuffers[tempName] = temporarySoundBuffer;
	}

	m_soundBuffers = tempSoundBuffers;
}

ce::ResourceManager::ResourceManager(const std::string & configFilePath, ce::ErrorCode::ResourceManager * errCode)
{
	ConfigFile cfg;
	bool logErrors = errCode != nullptr;

	if (!cfg.LoadFromFile(configFilePath, false) &&
		logErrors)
	{
		*errCode = ErrorCode::ResourceManager::CFG_MASTER;
		return;
	}

	if (!cfg.Parse() &&
		logErrors)
	{
		*errCode = ErrorCode::ResourceManager::CFG_MASTER_BAD_PARSED;
		return;
	}

	loadTextures(cfg.GetData("TEXTURES"), errCode);
	if (*errCode != ErrorCode::ResourceManager::NONE &&
		logErrors)
	{
		return;
	}

	loadFonts(cfg.GetData("FONTS"), errCode);
	if (*errCode != ErrorCode::ResourceManager::NONE &&
		logErrors)
	{
		return;
	}

	// weird exceptions here
	loadSoundBuffers(cfg.GetData("SOUNDBUFFERS"), errCode);
	if (*errCode != ErrorCode::ResourceManager::NONE &&
		logErrors)
	{
		return;
	}
}

const sf::Texture & ce::ResourceManager::GetTexture(const std::string & key, ErrorCode::ResourceManager * errCode)
{
	for (auto it = m_textures.begin(); it != m_textures.end(); ++it)
	{
		if (it->first == key)
		{
			return m_textures[key];
		}
	}

	*errCode = ce::ErrorCode::ResourceManager::CANNOT_GET_TEXTURE_CANNOT_FIND;
	return m_templateTexture;
}

const sf::Font & ce::ResourceManager::GetFont(const std::string & key, ErrorCode::ResourceManager * errCode)
{
	for (auto it = m_fonts.begin(); it != m_fonts.end(); ++it)
	{
		if (it->first == key)
		{
			return m_fonts[key];
		}
	}

	*errCode = ce::ErrorCode::ResourceManager::CANNOT_GET_FONT_CANNOT_FIND;
	return m_templateFont;
}

const sf::SoundBuffer & ce::ResourceManager::GetSoundBuffer(const std::string & key, ErrorCode::ResourceManager * errCode)
{
	for (auto it = m_soundBuffers.begin(); it != m_soundBuffers.end(); ++it)
	{
		if (it->first == key)
		{
			return m_soundBuffers[key];
		}
	}

	*errCode = ce::ErrorCode::ResourceManager::CANNOT_GET_SOUNDBUFFER_CANNOT_FIND;
	return m_templateSoundBuffer;
}
