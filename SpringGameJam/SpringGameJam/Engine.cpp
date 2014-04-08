
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

	/*loadAudio("Audio/hurricane-02.mp3", "BlizzardWrath");
	loadAudio("Audio/Torch-SoundBible.com-1962622442.mp3", "InfernoWrath");
	loadAudio("Audio/thunder_sound_FX-Grant_Evans-1523270250.mp3", "LightningWrath");
	loadAudio("Audio/rain-07.mp3", "LightRain");
	loadAudio("Audio/rain-01.mp3", "HeavyRain");
	loadAudio("Audio/wind-howl-01.mp3", "LightSnow");
	loadAudio("Audio/wind-strong-01.mp3", "HeavySnow");
	loadAudio("Audio/Dove-SoundBible.com-1198030484.mp3", "PerfectWeather");
	loadAudio("Audio/Thunder-Mike_Koenig-315681025.mp3", "LightningWrath2");
	loadAudio("Audio/ice-cracking-01.mp3", "IceDeath");
	loadAudio("Audio/Electric Shock Zap-SoundBible.com-68983399.mp3", "ElectricDeath");
	loadAudio("Audio/Flame Arrow-SoundBible.com-618067908.mp3", "FireDeath");
	loadAudio("Audio/Large Fireball-SoundBible.com-301502490.mp3", "FireDeath2");
	loadAudio("Audio/Small Fireball-SoundBible.com-1381880822.mp3", "FireDeath3");*/

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
