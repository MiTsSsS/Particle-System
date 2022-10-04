#include "headers/ParticleManager.h"
#include <iostream>

ParticleManager::ParticleManager(std::vector<Particle> particles) {
	this->particles = particles;
}

ParticleManager::ParticleManager() {}

int ParticleManager::getParticleCount() {
	return particles.size();
}

void ParticleManager::addParticle(Particle particle) {
	particles.push_back(particle);
}

void ParticleManager::removeParticle(int elementPosition) {
	particles.erase(particles.begin() + elementPosition);
}

void ParticleManager::update(sf::RenderWindow& window) {
	for (int i = 0; i < particles.size(); i++) {
		window.draw(particles[i].shape);
		particles[i].move();
		particles[i].update();

		if (particles[i].getLifetime() <= 0) {
			removeParticle(i);
		}
	}
}