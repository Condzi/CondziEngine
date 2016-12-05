#pragma once
#include "Component.hpp"
#include "Engine/Logger/Logger.hpp"
#include <vector>
#include <typeinfo>
#include <memory>

namespace ce
{
	// Entity final class
	// You can add ce::Component childrens
	// (Starting invoke, at position 0,0)
	// It's highly recommended to have unique entities names 
	class Entity final :
		public sf::Drawable
	{
		friend class EntityHolder;

	private:
		void draw(sf::RenderTarget & target, sf::RenderStates states) const;
		static unsigned int makeID();

	public:
		// Entity class constructor (default)
		Entity();
		~Entity();

		// Returns position of entity
		sf::Vector2f GetPosition();
		// Returns reference to position of entity
		sf::Vector2f& GetPositionRef();
		// Returns name of entity
		std::string GetName();
		// Returns unique ID of entity
		unsigned int GetID();
		// Returns Entity Holder that entity is attached
		EntityHolder* GetEntityHolderAttachedTo();
		// Returns true if sleeping
		bool IsSleeping();
		// Invokes Entity if sleeps
		void Invoke();
		// Puts Entity to sleep if not sleep
		// If entity sleep Update will not update it
		void Sleep();

		// Sets name of entity
		// name - new name
		void SetName(const std::string & name);
		// Sets position of entity
		// position - new position
		void SetPosition(const sf::Vector2f & position);

		// Updates logic
		// frameTime - frame time or delta time
		// If you want to draw it, simply use it like other SFML drawable
		void Update(float frameTime);
		// Removes all components
		void RemoveAllComponents();


		// Adds component to entity
		// Returns pointer to component or nullptr if failed (see debug log)
		// Usasge: entity.AddComponent<AwesomeComponent>()->setAwesomeThing(1);
		template<class T>
		T* AddComponent()
		{
			if (std::is_same<Component, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to add component, trying to add not inherited Component (T is Component type)", Logger::MessageType::Error, Logger::Output::All);
			
				return nullptr;
			}

			if (std::is_same<BasicComponent, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to add component, trying to add not inherited Component (T is BasicComponent type)", Logger::MessageType::Error, Logger::Output::All);

				return nullptr;
			}

			if (std::is_same<DrawableComponent, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to add component, trying to add not inherited Component (T is DrawableComponent type)", Logger::MessageType::Error, Logger::Output::All);

				return nullptr;
			}

			if (std::is_same<UpdateabaleComponent, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to add component, trying to add not inherited UpdateableComponent (T is DrawableComponent type)", Logger::MessageType::Error, Logger::Output::All);

				return nullptr;
			}

			if (std::is_base_of<Component, T>())
			{
				for (auto & var : m_components)
					if (T *ptr = dynamic_cast<T*>(var.get()))
					{
						Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to add component, found same Component. Remove old one before adding new one", Logger::MessageType::Error, Logger::Output::All);

						return nullptr;
					}
				
				m_components.push_back(std::make_unique<T>());

				m_components.back()->onCreate();
				m_components.back()->m_entityAttachedTo = this;

				return dynamic_cast<T*>(m_components.back().get());
			}

			if (std::is_base_of<DrawableComponent, T>())
			{
				for (auto & var : m_components)
					if (T *ptr = dynamic_cast<T*>(var.get()))
					{
						Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to add component, found same DrawableComponent. Remove old one before adding new one", Logger::MessageType::Error, Logger::Output::All);

						return nullptr;
					}

				m_drawable.push_back(std::make_shared<T>());

				m_drawable.back()->onCreate();
				m_drawable.back()->m_entityAttachedTo = this;

				return dynamic_cast<T*>(m_drawable.back().get());
			}

			if (std::is_base_of<UpdateabaleComponent, T>())
			{
				for (auto & var : m_components)
					if (T *ptr = dynamic_cast<T*>(var.get()))
					{
						Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to add component, found same UpdateableComponent. Remove old one before adding new one", Logger::MessageType::Error, Logger::Output::All);

						return nullptr;
					}

				m_updatable.push_back(std::make_shared<T>());

				m_updatable.back()->onCreate();
				m_updatable.back()->m_entityAttachedTo = this;

				return dynamic_cast<T*>(m_updatable.back().get());
			}

			if (std::is_base_of<BasicComponent, T>())
			{
				for (auto & var : m_components)
					if (T *ptr = dynamic_cast<T*>(var.get()))
					{
						Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to add component, found same BasicComponent. Remove old one before adding new one", Logger::MessageType::Error, Logger::Output::All);

						return nullptr;
					}

				m_basic.push_back(std::make_shared<T>());

				m_basic.back()->onCreate();
				m_basic.back()->m_entityAttachedTo = this;

				return dynamic_cast<T*>(m_basic.back().get());
			}

			Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to add component, T is not a child of any Component related class", Logger::MessageType::Error, Logger::Output::All);
		
			return nullptr;
		}

		// Returns pointer to component or nullptr if failed (see debug log)
		// Usasge: entity.GetComponent<AwesomeComponent>()->setAwesomeThing(1);
		template<class T>
		T* GetComponent()
		{
			if (std::is_same<Component, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to get component, trying to get not inherited Component (T is Component type)", Logger::MessageType::Error, Logger::Output::All);

				return nullptr;
			}

			if (std::is_same<BasicComponent, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to get component, trying to get not inherited Component (T is BasicComponent type)", Logger::MessageType::Error, Logger::Output::All);

				return nullptr;
			}

			if (std::is_same<DrawableComponent, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to get component, trying to get not inherited Component (T is DrawableComponent type)", Logger::MessageType::Error, Logger::Output::All);

				return nullptr;
			}

			if (std::is_same<UpdateabaleComponent, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to get component, trying to get not inherited UpdateableComponent (T is DrawableComponent type)", Logger::MessageType::Error, Logger::Output::All);

				return nullptr;
			}

			if (std::is_base_of<Component, T>())
			{
				for (auto & c : m_components)
					if (T *eptr = dynamic_cast<T*>(c.get()))
					{
						return dynamic_cast<T*>(c.get());
					}
			}

			if (std::is_base_of<UpdateabaleComponent, T>())
			{
				for (auto & c : m_updatable)
					if (T *eptr = dynamic_cast<T*>(c.get()))
					{
						return dynamic_cast<T*>(c.get());
					}
			}

			if (std::is_base_of<DrawableComponent, T>())
			{
				for (auto & c : m_drawable)
					if (T *eptr = dynamic_cast<T*>(c.get()))
					{
						return dynamic_cast<T*>(c.get());
					}
			}

			if (std::is_base_of<BasicComponent, T>())
			{
				for (auto & c : m_basic)
					if (T *eptr = dynamic_cast<T*>(c.get()))
					{
						return dynamic_cast<T*>(c.get());
					}
			}

			Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to get component, cannot find", Logger::MessageType::Error, Logger::Output::All);

			return nullptr;
		}
		
		// Removes component from entity
		// Returns false if failed (see debug log)
		// Usage: entity.RemoveComponent<AwesomeComponent>()
		template<class T>
		bool RemoveComponent()
		{
			if (std::is_same<Component, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to remove component, trying to remove not inherited Component (T is Component type)", Logger::MessageType::Error, Logger::Output::All);
			}

			if (!std::is_base_of<Component, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to remove component, 'Component' is not base of 'T'", Logger::MessageType::Error, Logger::Output::All);

				return false;
			}

			for (auto itr = m_components.begin(); itr != m_components.end(); ++itr)
				if (T *eptr = dynamic_cast<T*>(*itr->get()))
				{
					delete *itr;
					m_components.erase(itr);
					
					return true;
				}

			Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to remove component, cannot find 'T'", Logger::MessageType::Error, Logger::Output::All);

			return false;
		}
		
		// Checks if entity has component
		// Returns false if doesn't
		template<class T>
		bool HasComponent()
		{
			if (std::is_same<Component, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to check if has component, trying to check not inherited Component (T is Component type)", Logger::MessageType::Error, Logger::Output::All);
				
				return false;
			}

			for (auto & c : m_components)
				if (T *eptr = dynamic_cast<T*>(c.get()))
				{
					return true;
				}

			return false;
		}

	private:
		std::vector< std::shared_ptr< ce::Component > > m_components;
		std::vector< std::shared_ptr< ce::BasicComponent > > m_basic;
		std::vector< std::shared_ptr< ce::UpdateabaleComponent > > m_updatable;
		std::vector< std::shared_ptr< ce::DrawableComponent > > m_drawable;
		sf::Vector2f m_position;
		std::string m_name;
		unsigned int m_id;
		bool m_isSleeping;

		EntityHolder * m_holderAttachedTo;

	};
}
