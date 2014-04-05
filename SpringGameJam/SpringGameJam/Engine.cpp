
#include "Engine.h"
#include <iostream>

Engine::Engine()
	:gameClock()
{
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");

	//loadAssets();
}

Engine::~Engine()
{
	delete window;
}

void Engine::loadAssets()
{

}

sf::RenderWindow* Engine::getWindow()
{
	return window;
}

void Engine::update()
{
	sf::Time deltaTime = gameClock.getElapsedTime();
	std::cout << deltaTime.asSeconds() << std::endl;
	gameClock.restart();
}

void Engine::draw()
{
	window->clear();
    window->display();
}
