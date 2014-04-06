
#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(std::string TextureKey, int maxParticles)
	:tKey(TextureKey),
	mParticles(maxParticles)
{

}

ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::createPaticle()
{
	//particleList.insert(new Particle(sf::Sprite(txtMap->at(tKey)), sf::Vector2f(std::rand() % SCREEN_WIDTH, -10.0f), 
	//	sf::Vector2f(std::rand() % 3, std::rand() % 2 - 1)));
}