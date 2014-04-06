
#include "Engine.h"
#include <iostream>

Engine::Engine()
	:gameClock()
{
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");

	loadAssets();

	gameWorld = new World();
}

Engine::~Engine()
{
	delete gameWorld;
	delete window;
}

void Engine::loadAssets()
{
	loadTexture("Images/NightBackground.png", "NightBackground");
	loadTexture("Images/EveningBackGround.png", "EveningBackGround");
	loadTexture("Images/DayBackground.png", "DayBackground");
	loadTexture("Images/moisture.png", "Moisture");
	loadTexture("Images/Temperature.png", "Temperature");
}

void Engine::loadTexture(std::string filePath, std::string KeyName)
{
	sf::Texture tempText;
	if(!tempText.loadFromFile(filePath))
	{
		std::cout << KeyName << " texture was not loaded!" << std::endl;
		window->close();
	}
	txtMap->insert(MapPair(KeyName, tempText));

}

sf::RenderWindow* Engine::getWindow()
{
	return window;
}

void Engine::handleInput()
{
	gameWorld->handleInput();
}

void Engine::update()
{
	sf::Time deltaTime = gameClock.getElapsedTime();
	gameWorld->update(deltaTime.asSeconds());
	//std::cout << deltaTime.asSeconds() << std::endl;
	gameClock.restart();
}

void Engine::draw()
{
	window->clear();
	gameWorld->draw(window);
    window->display();
}
