#pragma once
#include "headers/Particle.h"
#include <vector>

class ParticleManager {
public:
	ParticleManager() = default;
	explicit ParticleManager(std::vector<Particle> particles);

	int getParticleCount() const;

	void initializeParticlePool();
	void addParticle(Particle particle);
	void removeParticle(int elementPosition);
	void poolParticle(sf::Vector2f position);
	void update(sf::RenderWindow& window);

private:
	std::vector<Particle> m_particles;
	int m_particlePoolIterator {0};
	int m_activeParticleCount {0};
};