#include "ball.h"

Ball::Ball(float startX, float startY)
{
	m_position.x = startX;
	m_position.y = startY;

	m_shape.setSize(sf::Vector2f(10, 10));
	m_shape.setPosition(m_position);
}

sf::FloatRect Ball::getPosition()
{
	return m_shape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
	return m_shape;
}

float Ball::getXVelocity()
{
	return m_directionX;
}

void Ball::bounceSides()
{
	m_directionX = -m_directionX;
}

void Ball::bounceTop()
{
	m_directionY = -m_directionY;
}

void Ball::missBottom()
{
	m_position.x = 1280 / 2;
	m_position.y = 0;
}

void Ball::hitBall()
{
	m_directionY = -m_directionY;
}

void Ball::update(sf::Time dt)
{
	m_position.y += m_directionY * m_speed * dt.asSeconds();
	m_position.x += m_directionX * m_speed * dt.asSeconds();

	m_shape.setPosition(m_position);
}