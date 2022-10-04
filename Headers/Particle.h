#pragma once
#include <SFML/Graphics.hpp>

class Particle {
private:
	sf::Vector2f velocity;
	sf::Color color;
	sf::Clock clock;
	sf::Time time;
	
	bool shouldFlipDirection{ false };
	float directionChange{ 1.0f };

	double angle;
	double radius;
	double lifetime;
	double speed;

public:
	sf::CircleShape shape;
	sf::Vector2f position;

	Particle(sf::Vector2f, sf::Vector2f, sf::Color, double, double, double, double);
	double getLifetime();
	void move();
	void update();
};