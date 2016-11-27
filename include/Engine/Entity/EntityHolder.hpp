#pragma once
#include "Engine/Entity/Entity.hpp"

namespace ce
{
	// Simple wrapper for std::vector 
	class EntityHolder :
		public sf::Drawable
	{
	private:
		void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	public:
		// Entity Holder constructor (default)
		EntityHolder();
	
		// Returns true if Entity of given name exist
		// name - entity name
		bool HasEntity(const std::string & name);
		// Returns pointer to Entity (nullptr if failed)
		// name - entity name
		Entity * GetEntity(const std::string & name);
		// Returns pointer to Entity (nullptr if failed)
		// id - entity id
		Entity * GetEntity(unsigned int id);
		// Adds Entity to Holder
		// Returns pointer to it
		// Usage: holder.AddEntity().SetName("MyNewEntity");
		Entity * AddEntity();
		// Removes Entity from Holder
		// Returns false if cannot find 
		// name - entity name
		bool RemoveEntity(const std::string & name);
		// Removes all Entities from Holder
		void RemoveAll();
		// Sleeps all Entities in Holder
		void SleepAll();
		// Invokes all Entities in Holder
		void InvokeAll();

		// Updates all entities
		// deltaTime - frame time or delta time
		void UpdateAll(float deltaTime);

		Entity& operator[](unsigned int index);
		// Returns amount of entities
		unsigned int GetSize();

	private:
		std::vector< Entity > m_entities;

	};
}
