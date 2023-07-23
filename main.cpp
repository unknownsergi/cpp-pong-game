#include <iostream>
#include "SFML/Graphics.hpp"
#include "ball.h"
#include "paddle.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main()
{
	// Create Window
	sf::VideoMode videoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
	sf::RenderWindow window(videoMode, "Pong-Game", sf::Style::Titlebar | sf::Style::Close);
	sf::Clock clock;
	Ball myBall(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	Paddle myPaddle(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 20);

	// Game Loop
	sf::Time dt;
	sf::Event e;

	float bounceTimer = 0.10f;

	while (window.isOpen())
	{
		// Update

		dt = clock.restart();
		bounceTimer -= dt.asSeconds();

		// Event

		if (myBall.getPosition().intersects(myPaddle.getPosition()))
		{
			if (bounceTimer < 0)
			{
				bounceTimer = 0.10f;
				myBall.hitBall();
			}
		}

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		// Close Window

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		// Move Paddle

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			myPaddle.moveLeft();
		else
			myPaddle.stopLeft();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			myPaddle.moveRight();
		else
			myPaddle.stopRight();
		


		if (myBall.getPosition().left < 0 || myBall.getPosition().left + myBall.getPosition().width > WINDOW_WIDTH)
		{
			myBall.bounceSides();
		}

		if (myBall.getPosition().top < 0  && bounceTimer < 0)
		{
			bounceTimer = 0.10f;
			myBall.bounceTop();
		}

		if (myBall.getPosition().top + myBall.getPosition().height > WINDOW_HEIGHT)
		{
			myBall.missBottom();
		}

		window.clear(sf::Color::Black);
		myBall.update(dt);
		myPaddle.update(dt);


		// Draw
		window.draw(myBall.getShape());
		window.draw(myPaddle.getShape());
		window.display();
	}

	return 0;
}