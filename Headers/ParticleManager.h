#pragma once

#include "headers/Particle.h"

#include <vector>

class ParticleManager {

public:

	ParticleManager() = default;

	int getParticleCount() const;

	void initializeParticlePool();
	void removeParticle(int elementPosition);
	void poolParticle(sf::Vector2f position);
	void update(sf::RenderWindow& window);

private:

	using Particles = std::vector<std::unique_ptr<Particle>>;

	Particles m_particles;

	int m_particlePoolIterator {0};
	int m_activeParticleCount {0};
};