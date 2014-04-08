
#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "Entity.h"
#include "Globals.h"
#include "World.h"

class Engine
{
private:
	World* gameWorld;
	sf::RenderWindow* window;
	sf::Clock gameClock;

	void loadAssets();
	void loadTexture(std::string filePath, std::string KeyName);
	//KTZ was here...
	//added function to load audio files
	void loadAudio(std::string filePath, std::string KeyName);

public:
	Engine();
	~Engine();
	sf::RenderWindow* getWindow();
	void handleInput();
	void update();
	void draw();
};

#endif