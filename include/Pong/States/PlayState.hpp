#pragma once
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <chrono>
#include <random>
#include "Engine/Managing/State.hpp"

class PlayState :
	public ce::State
{
private:
	void randBallVelocityVector();
	void setResources();
	void resetPositions();
	// returns false if exit
	bool handleEvents(const sf::Event & event);
	void handleRealTimeEvents(float & deltaTime);
	void update(float & deltaTime);
	void draw();

	void handleCollisions();

public:
	PlayState(const std::string & reosurceCacheConfig);

	short Run();

private:
	sf::RectangleShape m_paddleA;
	sf::RectangleShape m_paddleB;
	sf::RectangleShape m_ball;

	sf::Sound m_soundBallHit;
	sf::Sound m_soundScore;

	unsigned char m_counterA;
	unsigned char m_counterB;

	sf::Text m_textCounterA;
	sf::Text m_textCounterB;

	sf::Font m_font;

	sf::Vector2f m_ballVelocityVector;
};