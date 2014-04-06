
#include "World.h"

World::World()
	:background(txtMap->at("DayBackground")),
	gameWeather(new Weather())
{
	//gameSpawner = new Spawner();
}

World::~World()
{
	delete gameWeather;
	//delete gameSpawner;
}

void World::handleInput()
{
	//Changes the background to be different based on the light sensor
	if(sf::Keyboard::isKeyPressed(dayButton))
	{
		background = sf::Sprite(txtMap->at("DayBackground"));
	}
	if(sf::Keyboard::isKeyPressed(eveningButton))
	{
		background = sf::Sprite(txtMap->at("EveningBackGround"));
	}
	if(sf::Keyboard::isKeyPressed(nightButton))
	{
		background = sf::Sprite(txtMap->at("NightBackground"));
	}

	gameWeather->handleInput();
}

void World::update(float deltaTime)
{
	gameWeather->update(deltaTime);
	//gameSpawner->update(deltaTime);
}

void World::draw(sf::RenderWindow* w)
{
	w->draw(background);
	gameWeather->draw(w);
	//gameSpawner->draw(w);
}

