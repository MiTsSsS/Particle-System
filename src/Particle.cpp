#define _USE_MATH_DEFINES
#include "Headers/Particle.h"
#include <cmath>
#include <time.h>
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
	float newY = sin(angle) * speed;
	float newX = cos(angle) * speed;

	position.y += newY + directionChange;
	position.x += newX;
	
	if (directionChange >= 1.0f) {
		shouldFlipDirection = true;
	}

	else if(directionChange <= 1.0f && shouldFlipDirection == false) {
		directionChange -= 0.2f;
	}

	if (shouldFlipDirection) {
		directionChange += 0.2f;
	}
}

void Particle::update() {
	time = clock.getElapsedTime();
	//std::cout << time.asSeconds() << std::endl;
	if (time.asSeconds() >= lifetime) {
		this->shape.setRadius(0.0f);
		return;
	}

	shape.setPosition(position);
}