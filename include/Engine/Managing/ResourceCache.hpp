#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include "Engine/Logger/Logger.hpp"
#include "Engine/ConfigFileReader/ConfigFile.hpp"

namespace ce
{
	// - Textures
	// - Fonts
	// - SoundBuffers
	class ResourceCache
	{
	private:
		void loadTextures(std::string & configFilePath);
		void loadFonts(std::string & configFilePath);
		void loadSoundBuffers(std::string & configFilePath);
		void loadMusic(std::string & configFilePath);

	public:
		// configFilePath - path to cfg file with paths to textures, fonts and sound buffers
		ResourceCache(const std::string & configFilePath);

		const sf::Texture & GetTexture(const std::string & key);
		const sf::Font & GetFont(const std::string & key);
		const sf::SoundBuffer & GetSoundBuffer(const std::string & key);
		sf::Music & GetMusic(const std::string & key);

	private:
		std::map< std::string, sf::Texture > m_textures;
		std::map< std::string, sf::Font > m_fonts;
		std::map< std::string, sf::SoundBuffer > m_soundBuffers;
		std::map< std::string, sf::Music > m_music;

		sf::Texture m_templateTexture;
		sf::Font m_templateFont;
		sf::SoundBuffer m_templateSoundBuffer;
		sf::Music m_templateMusic;
	};
}