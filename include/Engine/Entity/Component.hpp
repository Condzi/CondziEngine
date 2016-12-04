#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace ce
{
	// Basic Component class
	// Be sure your component have default constructor!
	// Methods for override:
	// [private]
	// void onCreate()
	// void onDelete()
	// void onSleep()
	// void onInvoke()
	class BasicComponent
	{
		friend class Entity;

	private:
		virtual void onCreate();
		virtual void onDelete();
		virtual void onSleep();
		virtual void onInvoke();

	public:
		BasicComponent();
		virtual ~BasicComponent() = default;

		ce::Entity * GetEntityAttachedTo();

	private:
		ce::Entity * m_entityAttachedTo;

	};

	// Drawable Component class
	// Be sure your component have default constructor!
	// Methods to override:
	// [private]
	// void draw(sf::RenderTarget &, sf::RenderStates) const
	// void onCreate()
	// void onDelete()
	// void onSleep()
	// void onInvoke()
	class DrawableComponent :
		public ce::BasicComponent,
		public sf::Drawable
	{
		friend class Entity;
		
	private:
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	public:
		DrawableComponent();
		virtual ~DrawableComponent() = default;
	};

	// Updatable Component class
	// Be sure your component have default constructor!
	// Methods to override:
	// [private]
	// void update(float)
	// void onCreate()
	// void onDelete()
	// void onSleep()
	// void onInvoke()
	class UpdatebaleComponent :
		public ce::BasicComponent
	{
		friend class Entity;

	private:
		virtual void update(float);

	public:
		UpdatebaleComponent();
		virtual ~UpdatebaleComponent() = default;
	};

	// Component class (Updatable Component + Drawable Component )
	// Be sure your component have default constructor!
	// Methods to override:
	// [private]
	// void draw(sf::RenderTarget&, sf::RenderStates) const
	// void update(float)
	// void onCreate()
	// void onDelete()
	// void onSleep()
	// void onInvoke()
	class Component :
		public ce::DrawableComponent,
		public ce::UpdatebaleComponent
	{
		friend class Entity;

	public:
		Component();
		virtual ~Component() = default;
	};
}