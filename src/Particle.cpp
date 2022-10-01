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
	position.y += velocity.y * speed;

	//position.x += 5 * cos(position.x / 25);
	position.x += 5 * sin(position.y / 25) * velocity.y;
}

void Particle::update() {
	shape.setPosition(position);
}