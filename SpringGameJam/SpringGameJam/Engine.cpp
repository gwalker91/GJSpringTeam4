
#include "Engine.h"
#include <iostream>

Engine::Engine()
	:gameClock(),
	saved(false)
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
	loadTexture("Images/RainDrop.png", "RainDrop");
	loadTexture("Images/Snow.png", "Snow");
	loadTexture("Images/Wrath.png", "Wrath");
	loadTexture("Images/WrathBar.png", "WrathBar");
}

void Engine::loadTexture(std::string filePath, std::string KeyName)
{
	sf::Texture* tempText = new sf::Texture();
	if(!(*tempText).loadFromFile(filePath))
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
	if(!saved)
	{
		if(sf::Keyboard::isKeyPressed(saveButton))
		{
			saved = true;
		}
		if(sf::Keyboard::isKeyPressed(upGravityButton))
		{
			gravity += 0.1f;
		}
		if(sf::Keyboard::isKeyPressed(downGravityButton))
		{
			gravity -= 0.1f;
		}
		gameWorld->handleInput();
	}
	else
	{
		if(sf::Keyboard::isKeyPressed(saveButton))
		{
			saved = false;
		}
	}
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
