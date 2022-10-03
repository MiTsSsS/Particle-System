#include "headers/ParticleManager.h"

ParticleManager::ParticleManager(std::vector<Particle> particles) {
	this->particles = particles;
}

ParticleManager::ParticleManager() {}

void ParticleManager::addParticle(Particle particle) {
	particles.push_back(particle);
}

void update() {
	
}