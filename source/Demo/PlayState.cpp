#include "Demo/PlayState.hpp"

void demo::PlayState::onActivation()
{
	EntityFactory::MakeBackground(m_entityHolder.AddEntity())->SetName("Background");
	EntityFactory::MakeCar(m_entityHolder.AddEntity())->SetName("Player");
}

void demo::PlayState::onDeactivation()
{
	m_entityHolder.RemoveAll();
}

demo::PlayState::PlayState(const std::string & resourceCachePath) :State(resourceCachePath)
{
	EntityFactory::SetResourceCachePointer(m_resourceCache);
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
