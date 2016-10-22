#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "ErrorCodes.hpp"
#include "ConfigFileReader/ConfigFile.hpp"

namespace ce
{
	// Managing:
	// - Textures
	// - Fonts
	// - SoundBuffers
	// Every method have addintional argument - errCode - if is, then if error occured is stored in errCode
	class ResourceManager
	{
	private:
		void loadTextures(std::string & configFilePath, ErrorCode::ResourceManager * errCode = nullptr);
		void loadFonts(std::string & configFilePath, ErrorCode::ResourceManager * errCode = nullptr);
		void loadSoundBuffers(std::string & configFilePath, ErrorCode::ResourceManager * errCode = nullptr);

	public:
		// configFilePath - path to cfg file with paths to textures, fonts and sound buffers
		ResourceManager(const std::string & configFilePath, ErrorCode::ResourceManager * errCode = nullptr);

		const sf::Texture & GetTexture(const std::string & key, ErrorCode::ResourceManager * errCode = nullptr);
		const sf::Font & GetFont(const std::string & key, ErrorCode::ResourceManager * errCode = nullptr);
		const sf::SoundBuffer & GetSoundBuffer(const std::string & key, ErrorCode::ResourceManager * errCode = nullptr);

	private:
		std::map< std::string, sf::Texture > m_textures;
		std::map< std::string, sf::Font > m_fonts;
		std::map< std::string, sf::SoundBuffer > m_soundBuffers;

		sf::Texture m_templateTexture;
		sf::Font m_templateFont;
		sf::SoundBuffer m_templateSoundBuffer;
	};
}