#include "headers/ParticleManager.h"
#include <iostream>

ParticleManager::ParticleManager(std::vector<Particle> particles) {
	this->m_particles = particles;
}

int ParticleManager::getParticleCount() const {
	return m_activeParticleCount;
}

void ParticleManager::initializeParticlePool() {
	for(int i = 0; i < 999; i++) {
		Particle testParticle(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2.5f, 1.0f), sf::Color::Red, rand() % 361, 5.0f, 5.0f, 8.0f);
		addParticle(testParticle);
	}
}

void ParticleManager::addParticle(Particle particle) {
	m_particles.push_back(particle);
}

void ParticleManager::removeParticle(int elementPosition) {
	m_particles.erase(m_particles.begin() + elementPosition);
}

void ParticleManager::poolParticle(sf::Vector2f position) {
	m_particlePoolIterator++;
	m_activeParticleCount++;

	m_particles[m_particlePoolIterator].getPosition() = position;
	m_particles[m_particlePoolIterator].setIsActive(true);

	if(m_particlePoolIterator == 999)
		m_particlePoolIterator = 0;
}

void ParticleManager::update(sf::RenderWindow& window) {
	for(int i = 0; i < m_particles.size(); i++) {
		if(m_particles[i].getIsActive()) {
			m_particles[i].move();
			m_particles[i].update();
			window.draw(m_particles[i].getShape());

			if(m_particles[i].getLifetime() <= 0) {
				m_particles[i].reset();
				m_activeParticleCount--;
			}
		}
	}
}