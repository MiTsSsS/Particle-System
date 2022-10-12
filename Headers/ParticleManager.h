#pragma once
#include "headers/Particle.h"
#include <vector>

class ParticleManager {
private:
	std::vector<Particle> particles;
	int particlePoolIterator {0};

public:
	ParticleManager();
	ParticleManager(std::vector<Particle>);

	int getParticleCount();
	void initializeParticlePool();
	void addParticle(Particle);
	void removeParticle(int);
	void poolParticle(sf::Vector2f);
	void update(sf::RenderWindow&);
};