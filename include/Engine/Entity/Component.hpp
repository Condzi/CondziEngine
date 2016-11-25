#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace ce
{
	// virtual class Component
	// Inherit from it if you want to add Component to your Entity
	// Be sure your class have default constructor!
	// Methods to override: 
	// void draw(sf::RenderTarget& target, sf::RenderStates states) const
	// void update(float deltaTime)
	// void onCreate()
	// void onDelete()
	// void onSleep()
	// void onInvoke()
	class Component :
		public sf::Drawable
	{
	private:
		friend class Entity;

		virtual void onCreate();
		virtual void onDelete();
		virtual void onSleep();
		virtual void onInvoke();
		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
		virtual void update(float dt);

	public:
		// Component constructor (default)
		Component();
		virtual ~Component() = default;

		Entity& GetEntityAttachedTo();

	private:
		Entity * m_entityAttachedTo;

	};
}