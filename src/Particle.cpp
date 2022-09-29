#include "Headers/Particle.h"
#include <cmath>
#include <iostream>

Particle::Particle(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, double angle, double radius, double lifetime, double speed) {
	this->position = position;
	this->velocity = velocity;
	this->color = color;
	this->angle = angle;
	this->radius = radius;
	this->lifetime = lifetime;
	this->speed = speed;

	this->shape.setFillColor(color);
	this->shape.setRadius(radius);
	this->shape.setPosition(position);
}

void Particle::move() {
	//position.x += velocity.x * speed;
	std::cout << position.y << std::endl;
	position.x += 5 * sin(position.y / 25) * velocity.y;
	position.y += velocity.y * speed;
}

void Particle::update() {
	shape.setPosition(position);
}