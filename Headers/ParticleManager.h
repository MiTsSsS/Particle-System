#pragma once
#include "headers/Particle.h"
#include <vector>

class ParticleManager {
private:
	std::vector<Particle> particles;

public:
	ParticleManager();
	ParticleManager(std::vector<Particle>);

	int getParticleCount();
	void addParticle(Particle);
	void removeParticle(int);
	void update(sf::RenderWindow&);
};