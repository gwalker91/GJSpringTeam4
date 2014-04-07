
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
	//Backgrounds
	//reg
	loadTexture("Images/NightBackground.png", "regNightBackground");
	loadTexture("Images/EveningBackGround.png", "regEveningBackground");
	loadTexture("Images/DayBackground.png", "regDayBackground");
	//cold
	loadTexture("Images/NightBackground.png", "coldNightBackground");
	loadTexture("Images/EveningBackGround.png", "coldEveningBackground");
	loadTexture("Images/DayBackground.png", "coldDayBackground");
	//hot
	loadTexture("Images/NightBackground.png", "hotNightBackground");
	loadTexture("Images/EveningBackGround.png", "hotEveningBackground");
	loadTexture("Images/DayBackground.png", "hotDayBackground");


	//Particle textures
	loadTexture("Images/RainDrop.png", "RainDrop");
	loadTexture("Images/Snow.png", "Snow");

	//Wrath Textures
	loadTexture("Images/Wrath.png", "Wrath");
	loadTexture("Images/WrathBar.png", "WrathBar");

	//Darkness filter texture
	loadTexture("Images/darkness.png", "Darkness");

	//KTZ was here...
	//added the .png files as textures for the npcs
	loadTexture("Images/npcNormalSpriteSheetv1.png", "NormalHuman");
	loadTexture("Images/npcHotSpriteSheetv1.png", "BurningHuman");
	loadTexture("Images/npcColdSpriteSheet.png", "FreezingHuman");
	loadTexture("Images/hut.png", "Hut");

	std::cout << "Loaded the textures" << std::endl;
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
