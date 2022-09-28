#include "Headers/Particle.h"
#include <iostream>

Particle::Particle(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, double radius, double lifetime, double speed) {
	this->position = position;
	this->velocity = velocity;
	this->color = color;
	this->radius = radius;
	this->lifetime = lifetime;
	this->speed = speed;

	this->shape.setFillColor(color);
	this->shape.setRadius(radius);
	this->shape.setPosition(position);
}

void Particle::move() {
	position.x += velocity.x * speed;
	position.y += velocity.y * speed;
}

void Particle::update() {
	shape.setPosition(position);
}