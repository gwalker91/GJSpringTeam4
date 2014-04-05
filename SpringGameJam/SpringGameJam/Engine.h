
#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>

#include <vector>

#include "Entity.h"
#include "Globals.h"
#include "World.h"

class Engine
{
private:
	World gameWorld;
	sf::RenderWindow* window;
	sf::Clock gameClock;
	
	void loadAssets();
public:
	Engine();
	~Engine();
	sf::RenderWindow* getWindow();
	void update();
	void draw();
};

#endif