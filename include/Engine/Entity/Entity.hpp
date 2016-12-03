#pragma once
#include "Component.hpp"
#include "Engine/Logger/Logger.hpp"
#include <vector>
#include <typeinfo>

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
		// Returns amount of components removed
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
			}

			if (!std::is_base_of<Component, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to add component, 'Component' is not base of 'T'", Logger::MessageType::Error, Logger::Output::All);

				return nullptr;
			}

			for (auto & var : m_components)
				if (T *eptr = dynamic_cast<T*>(var))
				{
					Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to add component, found same component. Remove old one before adding new one", Logger::MessageType::Error, Logger::Output::All);

					return nullptr;
				}

			/*
			If you are here, probably you have just tried to add a component which
			is not a child of Component class
			*/
			m_components.push_back((new T()));
			// ^ !!! ^

			m_components[m_components.size() - 1]->onCreate();
			m_components[m_components.size() - 1]->m_entityAttachedTo = this;

			return dynamic_cast<T*>(m_components[m_components.size() - 1]);
		}

		// Returns pointer to component or nullptr if failed (see debug log)
		// Usasge: entity.GetComponent<AwesomeComponent>()->setAwesomeThing(1);
		template<class T>
		T* GetComponent()
		{
			if (std::is_same<Component, T>())
			{
				Logger::Log("Entity '" + m_name + "' (" + std::to_string(m_id) + "): Failed to get component, trying to get not inherited Component (T is Component type)", Logger::MessageType::Error, Logger::Output::All);
			}
		
			if (!std::is_base_of<Component, T>())
			{
				Logger::Log("Entity '" + m_name +"' (" + std::to_string(m_id) + "): Failed to get component, 'Component' is not base of 'T'", Logger::MessageType::Error, Logger::Output::All);

				return nullptr;
			}

			for (auto & c : m_components)
				if (T *eptr = dynamic_cast<T*>(c))
				{
					return dynamic_cast<T*>(c);
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
				if (T *eptr = dynamic_cast<T*>(*itr))
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
				if (T *eptr = dynamic_cast<T*>(c))
				{
					return true;
				}

			return false;
		}


	private:
		std::vector< ce::Component* > m_components;
		sf::Vector2f m_position;
		std::string m_name;
		unsigned int m_id;
		bool m_isSleeping;

		EntityHolder * m_holderAttachedTo;

	};
}
