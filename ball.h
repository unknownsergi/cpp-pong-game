#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::Vector2f m_position;
	sf::RectangleShape m_shape;
	
	float m_speed = 500;
	float m_directionX = 1.0f;
	float m_directionY = 1.0f;

public:
	Ball(float startX, float startY);
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	float getXVelocity();
	void bounceSides();
	void bounceTop();
	void missBottom();
	void hitBall();
	void update(sf::Time dt);


};