#include "Demo/PlayState.hpp"

demo::PlayState::PlayState(const std::string & resourceCachePath) :State(resourceCachePath)
{
}

short demo::PlayState::Run()
{
	sf::Event ev;
	sf::Clock deltaClock;
	float deltaTime = 0.0f;

	while (true)
	{
		while (m_window->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				return (int)demo::State::Exit;
		}

		m_entityHolder.UpdateAll(deltaTime);

		m_window->clear();
		m_window->draw(m_entityHolder);
		m_window->display();

		deltaTime = deltaClock.restart().asSeconds();
	}
}
