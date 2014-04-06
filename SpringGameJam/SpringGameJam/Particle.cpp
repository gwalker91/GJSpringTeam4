
#include "Particle.h"

Particle::Particle(sf::Sprite image, sf::Vector2f position, sf::Vector2f velocity)
	:pImage(image),
	position(position),
	velocity(velocity),
	isAlive(true),
	timeToLive(10)
{
	pImage.setPosition(position);
}

Particle::~Particle()
{

}

void Particle::killParticle()
{
	isAlive = false;
}

bool Particle::checkState()
{
	return isAlive;
}

void Particle::changeTexture(sf::Sprite image)
{
	pImage = image;
}

void Particle::update(float deltaTime)
{
	timeToLive -= deltaTime;
	position += velocity * (deltaTime * gravity);
	pImage.setPosition(position);

	if(position.y > SCREEN_HEIGHT || timeToLive <= 0)
	{
		killParticle();
	}
}

void Particle::draw(sf::RenderWindow* w)
{
	w->draw(pImage);
}