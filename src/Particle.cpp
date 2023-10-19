#define _USE_MATH_DEFINES
#include "Headers/Particle.h"
#include <cmath>
#include <time.h>
#include <iostream>

Particle::Particle(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, float radius, double angle, double lifetime, double speed)
	: m_velocity {velocity}, m_position {position}, m_color {color}, m_radius {radius}, m_angle {angle * (M_PI / 180)}, m_lifetime {lifetime}, m_speed {speed} {

	this->m_shape.setFillColor(color);
	this->m_shape.setRadius(radius);
	this->m_shape.setPosition(position);
}

double Particle::getLifetime() const {
	return m_lifetime;
}

bool Particle::getIsActive() const {
	return m_isActive;
}

sf::CircleShape Particle::getShape() const {
	return m_shape;
}

sf::Vector2f Particle::getPosition() const {
	return m_position;
}

void Particle::setIsActive(bool active) {
	this->m_isActive = active;

	if (active)
		m_clock.restart();
}

void Particle::move() {
	double newY = sin(m_angle) * m_speed;
	double newX = cos(m_angle) * m_speed;

	m_position.y += newY + m_directionChange;
	m_position.x += newX;

	if (m_directionChange >= 1.0f) {
		m_shouldFlipDirection = true;
	}

	else if (m_directionChange <= 1.0f && m_shouldFlipDirection == false) {
		m_directionChange -= 0.2f;
	}

	if (m_shouldFlipDirection) {
		m_directionChange += 0.2f;
	}
}

void Particle::update() {
	m_time = m_clock.getElapsedTime();
	m_lifetime -= m_time.asSeconds();
	m_shape.setPosition(m_position);
}

void Particle::reset() {
	setIsActive(false);
	m_shouldFlipDirection = false;
	m_directionChange = 1.0f;
	m_lifetime = 5.0f;
}