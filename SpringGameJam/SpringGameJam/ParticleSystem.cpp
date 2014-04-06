
#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(std::string TextureKey, int maxParticles)
	:tKey(TextureKey),
	mParticles(maxParticles),
	timeToSpawnDrop(0),
	spawnDensity(0.01f)
{
}

ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::createParticle()
{
	particleList.push_back(Particle(sf::Sprite((*txtMap->at(tKey))), sf::Vector2f(std::rand() % SCREEN_WIDTH, -10.0f), 
		sf::Vector2f(0, std::rand() % 200 + 100)));
}

void ParticleSystem::changeTexture(std::string TextureKey)
{
	tKey = TextureKey;
	if(particleList.size() > 0)
	{
		for (int i = 0; i < particleList.size(); i++)
		{
			if(particleList.at(i).checkState())
				particleList.at(i).changeTexture(sf::Sprite((*txtMap->at(tKey))));
		}
	}
}

void ParticleSystem::changeDensity(int weather)
{
	switch (weather)
	{
	//Dry Weather
	case 0:
		spawnDensity = 100;
		break;
	//Mild weather
	case 1:
		spawnDensity = 0.1f;
		break;
	//Heavy Rain
	case 2:
		spawnDensity = 0.01f;
		break;

	}
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
	if(timeToSpawnDrop > spawnDensity && particleList.size() < mParticles)
	{
		createParticle();
		timeToSpawnDrop = 0;
	}
	if(particleList.size() > 0)
	{
		for (int i = 0; i < particleList.size(); i++)
		{
			if(particleList.at(i).checkState())
				particleList.at(i).update(deltaTime);
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
		particleList.at(i).draw(w);
	}
}