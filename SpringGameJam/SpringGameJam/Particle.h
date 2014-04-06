
#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include "Globals.h"

class Particle
{
private:
	sf::Sprite pImage;
	sf::Vector2f position;
	sf::Vector2f velocity;
	bool isAlive;
	float timeToLive;

	void killParticle();
public:
	Particle(sf::Sprite image, sf::Vector2f position, sf::Vector2f velocity);
	~Particle();
	bool checkState();
	void changeTexture(sf::Sprite image);
	void update(float deltaTime);
	void draw(sf::RenderWindow* w);

};

#endif