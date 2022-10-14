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

double Particle::getLifetime() {
	return lifetime;
}

bool Particle::getIsActive() {
	return isActive;
}

void Particle::setIsActive(bool active) {
	this->isActive = active;

	if(active)
		clock.restart();
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
	lifetime -= time.asSeconds();
	shape.setPosition(position);
}

void Particle::reset() {
	setIsActive(false);
	shouldFlipDirection = false;
	directionChange = 1.0f;
	lifetime = 5.0f;
}