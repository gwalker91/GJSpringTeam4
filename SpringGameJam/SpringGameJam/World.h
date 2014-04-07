
#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

#include "Weather.h"
#include "Spawner.h"
#include "Globals.h"
#include "Wrath.h"

class World //: public Entity
{
private:
	Weather* gameWeather;
	Spawner* gameSpawner;
	Wrath* gameWrath;

	int lastTemp;

	sf::Sprite background;

	sf::Texture dayBackground;
	sf::Texture eveningBackground;
	sf::Texture nightBackground;

	void backGroundSwap();

public:
	World();
	~World();
	void handleInput();
	void update(float deltaTime);
	void draw(sf::RenderWindow* w);
};


#endif