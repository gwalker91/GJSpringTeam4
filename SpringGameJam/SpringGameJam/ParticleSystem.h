
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
	std::vector<Particle*>::iterator it;
	std::string tKey;
	int mParticles;	

	void createPaticle();
	
public:
	ParticleSystem(std::string TextureKey, int maxParticles);
	~ParticleSystem();
	void changeTexture(std::string TextureKey);
	void changeNumParticles(int maxParticles);
	void update(float deltaTime);
	void draw(sf::RenderWindow* w);
};



#endif