#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Debug/Debug.hpp"
#include "ConfigFileReader/ConfigFile.hpp"

namespace ce
{
	// Managing:
	// - Textures
	// - Fonts
	// - SoundBuffers
	class ResourceManager
	{
	private:
		void loadTextures(std::string & configFilePath);
		void loadFonts(std::string & configFilePath);
		void loadSoundBuffers(std::string & configFilePath);

	public:
		// configFilePath - path to cfg file with paths to textures, fonts and sound buffers
		ResourceManager(const std::string & configFilePath);

		const sf::Texture & GetTexture(const std::string & key);
		const sf::Font & GetFont(const std::string & key);
		const sf::SoundBuffer & GetSoundBuffer(const std::string & key);

	private:
		std::map< std::string, sf::Texture > m_textures;
		std::map< std::string, sf::Font > m_fonts;
		std::map< std::string, sf::SoundBuffer > m_soundBuffers;

		sf::Texture m_templateTexture;
		sf::Font m_templateFont;
		sf::SoundBuffer m_templateSoundBuffer;
	};
}