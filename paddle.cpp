#include "paddle.h"

Paddle::Paddle(float startX, float startY)
{
	m_position.x = startX;
	m_position.y = startY;

	m_shape.setSize(sf::Vector2f(200, 10));
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setOutlineColor(sf::Color::White);
	m_shape.setOutlineThickness(3);

	m_shape.setPosition(m_position);
}

sf::FloatRect Paddle::getPosition()
{
	return m_shape.getGlobalBounds();
}

sf::RectangleShape Paddle::getShape()
{
	return m_shape;
}

void Paddle::moveLeft()
{
	m_movingLeft = true;
}

void Paddle::moveRight()
{
	m_movingRight = true;
}

void Paddle::stopLeft()
{
	m_movingLeft = false;
}

void Paddle::stopRight()
{
	m_movingRight = false;
}

void Paddle::update(sf::Time dt)
{
	if (m_movingLeft)
	{
		m_position.x -= m_speed * dt.asSeconds();
	}

	if (m_movingRight)
	{
		m_position.x += m_speed * dt.asSeconds();
	}

	m_shape.setPosition(m_position);
}

