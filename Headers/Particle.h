#pragma once
#include <SFML/Graphics.hpp>

class Particle {
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	
	double radius;
	double lifetime;
	double speed;

public:
	sf::CircleShape shape;

	Particle(sf::Vector2f, sf::Vector2f, sf::Color, double, double, double);
	void move();
	void update();
};