#include "headers/ParticleManager.h"

#include <random>
#include <iostream>

int ParticleManager::getParticleCount() const {
	return m_activeParticleCount;
}

void ParticleManager::initializeParticlePool() {
	for (int i = 0; i < MAX_POOL_SIZE; ++i) {
		m_particles.push_back(std::make_unique<Particle>(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2.5f, 1.0f), sf::Color::Red, 5.0f, rand() % 361, 5.0f, 8.0f));
	}
}

void ParticleManager::removeParticle(int elementPosition) {
	m_particles.erase(m_particles.begin() + elementPosition);
}

void ParticleManager::poolParticle(sf::Vector2f position) {
	m_particlePoolIterator++;
	m_activeParticleCount++;

	m_particles[m_particlePoolIterator]->setPosition(position);
	m_particles[m_particlePoolIterator]->setIsActive(true);

	if (m_particlePoolIterator == MAX_POOL_SIZE - 1)
		m_particlePoolIterator = 0;
}

void ParticleManager::update(sf::RenderWindow& window) {
	for (const std::unique_ptr<Particle>& particle : m_particles) {
		if (particle->getIsActive()) {
			particle->move();
			particle->update();
			window.draw(particle->getShape());

			if (particle->getLifetime() <= 0) {
				particle->reset();
				m_activeParticleCount--;
			}
		}
	}
}