#pragma once
#include "Engine/Logger/Logger.hpp"
#include "Engine/ConfigFileReader/ConfigFile.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

namespace ce
{
	// Resource Cache (storage) for:
	// - Textures
	// - Fonts
	// - SoundBuffers
	// - Musics
	class ResourceCache
	{
	private:
		void loadTextures(std::string & configFilePath);
		void loadFonts(std::string & configFilePath);
		void loadSoundBuffers(std::string & configFilePath);
		void loadMusic(std::string & configFilePath);

	public:
		// ResourceCache constructor (not default)
		// configFilePath - path to cfg file with paths to textures, fonts...
		// If configPath = "" then nothing is trying to load.
		ResourceCache(const std::string & configFilePath);

		// Returns pointer to sf::Texture
		// key	- texture name
		sf::Texture * GetTexture(const std::string & key);
		// Returns pointer to sf::Font
		// key	- font name
		sf::Font * GetFont(const std::string & key);
		// Returns pointer to sf::SoundBuffer
		// key	- sound buffer name
		sf::SoundBuffer * GetSoundBuffer(const std::string & key);
		// Returns pointer to sf::Music.
		// key	- music name
		sf::Music * GetMusic(const std::string & key);

	private:
		std::map< std::string, sf::Texture > m_textures;
		std::map< std::string, sf::Font > m_fonts;
		std::map< std::string, sf::SoundBuffer > m_soundBuffers;
		std::map< std::string, sf::Music > m_music;
	};
}