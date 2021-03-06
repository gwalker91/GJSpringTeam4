
#include "Engine.h"
#include <iostream>

Engine::Engine()
	:gameClock()
{
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");

	srand (time(NULL));

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
	loadTexture("Images/BackgroundPleasantNight.png", "regNightBackground");
	loadTexture("Images/BackgroundPleasantEve.png", "regEveBackground");
	loadTexture("Images/BackgroundPleasantDay.png", "regDayBackground");
	//cold
	loadTexture("Images/BackgroundColdNight.png", "coldNightBackground");
	loadTexture("Images/BackgroundColdEve.png", "coldEveBackground");
	loadTexture("Images/BackgroundColdDay.png", "coldDayBackground");
	//hot
	loadTexture("Images/BackgroundHotNight.png", "hotNightBackground");
	loadTexture("Images/BackgroundHotEve.png", "hotEveBackground");
	loadTexture("Images/BackgroundHotDay.png", "hotDayBackground");

	//Particle textures
	loadTexture("Images/RainDrop.png", "RainDrop");
	loadTexture("Images/Snow.png", "Snow");

	//Wrath Textures
	loadTexture("Images/WrathSpriteSheet.png", "Wrath");
	loadTexture("Images/WrathBar.png", "WrathBar");

	//Darkness filter texture
	loadTexture("Images/darkness.png", "Darkness");

	//Weather textures
	loadTexture("Images/clouds.png", "Clouds");
	loadTexture("Images/cloudsHeavy.png", "HeavyClouds");	

	//KTZ was here...
	//added the .png files as textures for the npcs
	//added .mp3 files for sound effects (had to comment them out
	loadTexture("Images/npcNormalSpriteSheetv1.png", "NormalHuman");
	loadTexture("Images/npcHotSpriteSheetv1.png", "BurningHuman");
	loadTexture("Images/npcColdSpriteSheet.png", "FreezingHuman");
	loadTexture("Images/hut.png", "Hut");

	loadAudio("Audio/BlizzardWrath.wav", "BlizzardWrath");
	loadAudio("Audio/FlameWrath.wav", "InfernoWrath");
	loadAudio("Audio/ThunderWrath.wav", "LightningWrath");
	loadAudio("Audio/LightRain.wav", "LightRain");
	loadAudio("Audio/HeavyRain.wav", "HeavyRain");
	loadAudio("Audio/LightSnow.wav", "LightSnow");
	loadAudio("Audio/HeavySnow.wav", "HeavySnow");
	loadAudio("Audio/NormalDaySE.wav", "PerfectWeather");
	loadAudio("Audio/ThunderWrath2.wav", "LightningWrath2");
	loadAudio("Audio/IceDeath.wav", "IceDeath");
	loadAudio("Audio/ElectricDeath.wav", "ElectricDeath");
	loadAudio("Audio/flameDeath1.wav", "FireDeath");
	loadAudio("Audio/flameDeath2.wav", "FireDeath2");
	loadAudio("Audio/flameDeath3.wav", "FireDeath3");

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

void Engine::loadAudio(std::string filePath, std::string KeyName)
{
	sf::SoundBuffer* tempSound = new sf::SoundBuffer();
	if(!(*tempSound).loadFromFile(filePath))
	{
		std::cout << KeyName << " sound was not loaded!" << std::endl;
		window->close();
	}
	audMap->insert(MapPairAudio(KeyName, tempSound));
}

sf::RenderWindow* Engine::getWindow()
{
	return window;
}

void Engine::handleInput()
{
	if(sf::Keyboard::isKeyPressed(upGravityButton))
	{
		gravity = 2.0f;
	}
	if(sf::Keyboard::isKeyPressed(downGravityButton))
	{
		gravity = -2.0f;
	}
	if(sf::Keyboard::isKeyPressed(resetGravityButton))
	{
		gravity = 1.0f;
	}
	gameWorld->handleInput();

}

void Engine::update()
{
	sf::Time deltaTime = gameClock.getElapsedTime();
	gameWorld->update(deltaTime.asSeconds());
	gameClock.restart();
}

void Engine::draw()
{
	window->clear();
	gameWorld->draw(window);
    window->display();
}
