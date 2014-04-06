
#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(std::string TextureKey, int maxParticles)
	:tKey(TextureKey),
	mParticles(maxParticles),
	timeToSpawnDrop(0)
{
}

ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::createParticle()
{
	particleList.push_back(new Particle(sf::Sprite(txtMap->at(tKey)), sf::Vector2f(std::rand() % SCREEN_WIDTH, -10.0f), 
		sf::Vector2f(std::rand() % 10 - 5, std::rand() % 200 + 100)));
}

void ParticleSystem::changeTexture(std::string TextureKey)
{
	tKey = TextureKey;
}

void ParticleSystem::clearSystem()
{
	particleList.clear();
}
	
void ParticleSystem::changeNumParticles(int maxParticles)
{
	mParticles = maxParticles;
}

void ParticleSystem::update(float deltaTime)
{
	timeToSpawnDrop += deltaTime;
	if(timeToSpawnDrop > 0.01 && particleList.size() < mParticles)
	{
		createParticle();
		timeToSpawnDrop = 0;
	}
	if(particleList.size() > 0)
	{
		for (int i = 0; i < particleList.size(); i++)
		{
			if(particleList.at(i)->checkState())
				particleList.at(i)->update(deltaTime);
			else
			{
				particleList.erase(particleList.begin() + i);
			}
		}
	}

}

void ParticleSystem::draw(sf::RenderWindow* w)
{
	for (int i = 0; i < particleList.size(); i++)
	{
		particleList.at(i)->draw(w);
	}
}