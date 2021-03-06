#include "Demo/SpriteRendererComponent.hpp"

void demo::SpriteRenderer::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}

void demo::SpriteRenderer::update(float)
{
	m_sprite.setPosition(this->m_entityAttachedTo->GetPositionRef() + m_localPosition);
}

demo::SpriteRenderer::SpriteRenderer()
{
	m_localPosition = sf::Vector2f(0, 0);
}

void demo::SpriteRenderer::SetTexture(const sf::Texture * texture)
{
	if (texture == nullptr)
	{
		ce::Logger::Log("SpriteRenderer [" + std::to_string(this->m_entityAttachedTo->GetID()) + "]: Texture is nullptr", ce::Logger::MessageType::Error, ce::Logger::Output::All);
		
		return;
	}

	m_sprite.setTexture(*texture);
}

sf::Transformable & demo::SpriteRenderer::GetTransformable()
{
	return m_sprite;
}

sf::FloatRect demo::SpriteRenderer::GetRect()
{
	return m_sprite.getGlobalBounds();
}

void demo::SpriteRenderer::SetLocalPosition(sf::Vector2f position)
{
	m_localPosition = position;
	update(0.f);
}
