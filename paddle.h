#pragma once
#include <SFML/Graphics.hpp>


class Paddle
{
private:
	sf::Vector2f m_position;
	sf::RectangleShape m_shape;

	float m_speed = 1100.0f;

	bool m_movingLeft = false;
	bool m_movingRight = false;

public:
	Paddle(float startX, float startY);
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(sf::Time dt);

};