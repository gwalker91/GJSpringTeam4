
#ifndef WORLD_H
#define WORLD_H

#include "Weather.h"
#include "Spawner.h"

class World : public Entity
{
private:
	//Weather* gameWeather;
	//Spawner* gameSpawner;
public:
	//World();
	//~World();
	void update(float deltaTime);
	void draw(sf::RenderWindow w);

};


#endif