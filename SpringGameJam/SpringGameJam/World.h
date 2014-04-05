
#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

#include "Weather.h"
#include "Spawner.h"
#include "Globals.h"

class World //: public Entity
{
private:
	//Weather* gameWeather;
	//Spawner* gameSpawner;
	sf::Sprite background;
public:
	World();
	~World();
	void handleInput();
	void update(float deltaTime);
	void draw(sf::RenderWindow* w);

};


#endif