
#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "Globals.h"

class ParticleSystem
{
private:
	std::vector<Particle*> particleList;
	std::string tKey;
	int mParticles;
	float timeToSpawnDrop;
	float spawnDensity;

	void createParticle();
	
public:
	ParticleSystem(std::string TextureKey, int maxParticles);
	~ParticleSystem();
	void changeTexture(std::string TextureKey);
	void changeNumParticles(int maxParticles);
	void changeDensity(int weather);
	void clearSystem();
	void update(float deltaTime);
	void draw(sf::RenderWindow* w);
};



#endif