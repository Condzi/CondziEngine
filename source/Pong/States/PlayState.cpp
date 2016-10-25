#include "Pong/States/PlayState.hpp"

void PlayState::randBallVelocityVector()
{
	m_ballVelocityVector.x = std::rand() % -50 + 50;
	m_ballVelocityVector.y = std::rand() % -25 + 25;
}

void PlayState::setResources()
{
	m_paddleA.setTexture(&m_resourceCache->GetTexture("Paddle"));
	m_paddleB.setTexture(&m_resourceCache->GetTexture("Paddle"));
	m_ball.setTexture(&m_resourceCache->GetTexture("Ball"));

	m_soundBallHit.setBuffer(m_resourceCache->GetSoundBuffer("BallHit"));
	m_soundScore.setBuffer(m_resourceCache->GetSoundBuffer("Score"));

	m_textCounterA.setFont(m_resourceCache->GetFont("Default"));
	m_textCounterB.setFont(m_resourceCache->GetFont("Default"));
}

void PlayState::resetPositions()
{
	m_ball.setPosition(m_window->getSize().x / 2, m_window->getSize().y / 2);
	m_paddleA.setPosition(0 + m_paddleA.getSize().x, m_window->getSize().y / 2 - m_paddleA.getSize().y / 2);
	m_paddleB.setPosition(m_window->getSize().x - m_paddleA.getSize().x * 2, m_window->getSize().y / 2 - m_paddleA.getSize().y / 2);

	m_textCounterA.setPosition(m_window->getSize().x / 2 - m_textCounterA.getGlobalBounds().width, m_textCounterA.getGlobalBounds().height);
	m_textCounterB.setPosition(m_window->getSize().x / 2 + m_textCounterB.getGlobalBounds().width, m_textCounterB.getGlobalBounds().height);
}

bool PlayState::handleEvents(const sf::Event & event)
{
	if (event.type == sf::Event::Closed ||
		(event.type == sf::Event::KeyReleased &&
		event.key.code == sf::Keyboard::Key::Escape))
	{
		return false;
	}

	return true;
}

void PlayState::handleRealTimeEvents(float & deltaTime)
{
	float movementOffset = 250.f * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_paddleA.move(0, -movementOffset);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_paddleA.move(0, movementOffset);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_paddleB.move(0, -movementOffset);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_paddleB.move(0, movementOffset);
	}
}

void PlayState::update(float & deltaTime)
{
	m_ball.move(m_ballVelocityVector * deltaTime);
	m_ballVelocityVector.x *= 1.0005f;
}

void PlayState::draw()
{
	m_window->clear();

	m_window->draw(m_paddleA);
	m_window->draw(m_paddleB);
	m_window->draw(m_ball);

	m_window->draw(m_textCounterA);
	m_window->draw(m_textCounterB);

	m_window->display();
}

void PlayState::handleCollisions()
{
	if (m_ball.getPosition().x <= 0)
	{
		m_soundScore.play();
		++m_counterB;
		m_textCounterB.setString(std::to_string(m_counterB));
		resetPositions();
		randBallVelocityVector();
		
		return;
	}
	else if (m_ball.getPosition().x + m_ball.getGlobalBounds().width >= m_window->getSize().x)
	{
		m_soundScore.play();
		++m_counterA;
		m_textCounterA.setString(std::to_string(m_counterA));
		resetPositions();
		randBallVelocityVector();

		return;
	}
}

PlayState::PlayState(sf::RenderWindow & window, const std::string & reosurceCacheConfig) : State(window, reosurceCacheConfig)
{
	auto duration = std::chrono::system_clock::now().time_since_epoch();
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
	std::srand(millis);

	m_paddleA.setSize(sf::Vector2f(25, 100));
	m_paddleB.setSize(m_paddleA.getSize());
	m_ball.setSize(sf::Vector2f(10, 10));

	m_counterA = 0;
	m_counterB = 0;

	m_textCounterA.setString(std::to_string(m_counterA));
	m_textCounterB.setString(std::to_string(m_counterB));

	setResources();
	resetPositions();
	randBallVelocityVector();
}

short PlayState::Run()
{
	bool play = true;
	float deltaTime = 0.0f;
	sf::Clock fpsClock;
	sf::Event ev;

	while (play)
	{
		while (m_window->pollEvent(ev))
		{
			play = handleEvents(ev);
		}

		handleRealTimeEvents(deltaTime);
		update(deltaTime);
		handleCollisions();
		draw();

		deltaTime = fpsClock.restart().asSeconds();
	}

	return -1;
}
