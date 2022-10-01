#define _USE_MATH_DEFINES
#include "Headers/Particle.h"
#include <cmath>
#include <iostream>

Particle::Particle(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, double angle, double radius, double lifetime, double speed) {
	this->position = position;
	this->velocity = velocity;
	this->color = color;
	this->angle = angle * (M_PI / 180);
	this->radius = radius;
	this->lifetime = lifetime;
	this->speed = speed;

	this->shape.setFillColor(color);
	this->shape.setRadius(radius);
	this->shape.setPosition(position);
}

void Particle::move() {
	position.y += sin(angle) * speed;
	position.x += cos(angle) * speed;
}

void Particle::update() {
	shape.setPosition(position);
}