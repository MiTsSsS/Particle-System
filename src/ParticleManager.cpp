#include "headers/ParticleManager.h"
#include <iostream>

ParticleManager::ParticleManager(std::vector<Particle> particles) {
	this->particles = particles;
}

ParticleManager::ParticleManager() {}

int ParticleManager::getParticleCount() {
	return particles.size();
}

void ParticleManager::initializeParticlePool() {
	for (int i = 0; i < 999; i++) {
		Particle testParticle(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2.5f, 1.0f), sf::Color::Red, rand() % 361, 5.0f, 5.0f, 8.0f);
		addParticle(testParticle);
	}
}

void ParticleManager::addParticle(Particle particle) {
	particles.push_back(particle);
}

void ParticleManager::removeParticle(int elementPosition) {
	particles.erase(particles.begin() + elementPosition);
}

void ParticleManager::poolParticle(sf::Vector2f position) {
	particlePoolIterator++;

	std::cout << particlePoolIterator << std::endl;

	particles[particlePoolIterator].position = position;
	particles[particlePoolIterator].setIsActive(true);

	if (particlePoolIterator == 999)
		particlePoolIterator = 0;
}

void ParticleManager::update(sf::RenderWindow& window) {
	for (int i = 0; i < particles.size(); i++) {
		if (particles[i].getIsActive()) {
			window.draw(particles[i].shape);
			particles[i].move();
			particles[i].update();

			if (particles[i].getLifetime() <= 0) {
				particles[i].reset();
			}
		}		
	}
}