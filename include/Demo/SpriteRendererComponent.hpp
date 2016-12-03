#pragma once
#include "Engine/Entity/Component.hpp"
#include "Engine/Entity/Entity.hpp"
#include "Engine/Logger/Logger.hpp"
#include <SFML/Graphics/Sprite.hpp>

namespace demo
{
	class SpriteRenderer :
		public ce::Component
	{
	private:
		void draw(sf::RenderTarget & target, sf::RenderStates states) const;
		void update(float);

	public:
		SpriteRenderer();

		void SetTexture(sf::Texture * texture);
		sf::Transformable & GetTransformable();
		void SetLocalPosition(sf::Vector2f position);

	private:
		sf::Sprite m_sprite;
		sf::Vector2f m_localPosition;
	
	};
}