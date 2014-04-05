
#include "Engine.h"
#include <iostream>

Engine::Engine()
	:gameClock()
{
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");

	loadAssets();

	day = sf::Sprite(txtMap->at("DayBackground"));
	night = sf::Sprite(txtMap->at("NightBackground"));

	toDraw = day;
}

Engine::~Engine()
{
	//delete gameWorld;
	delete window;
}

void Engine::loadAssets()
{
	loadTexture("Images/NightBackground.png", "NightBackground");
	loadTexture("Images/DayBackground.png", "DayBackground");
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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		toDraw = day;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		toDraw = night;
	}
}

void Engine::update()
{
	sf::Time deltaTime = gameClock.getElapsedTime();
	//std::cout << deltaTime.asSeconds() << std::endl;
	gameClock.restart();
}

void Engine::draw()
{
	window->clear();
	window->draw(toDraw);
    window->display();
}
