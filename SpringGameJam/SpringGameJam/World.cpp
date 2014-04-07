
#include "World.h"

World::World()
	:dayBackground(*txtMap->at("coldDayBackground")),
	eveningBackground(*txtMap->at("coldEveningBackground")),
	nightBackground(*txtMap->at("regNightBackground")),
	background(sf::Sprite(dayBackground)),
	gameWeather(new Weather()),
	gameWrath(new Wrath()),
	gameSpawner(new Spawner(sf::Sprite(*txtMap->at("Hut")), sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT*0.60))),
	lastTemp(0)
{
	//KTZ was here... uncommented and fixed gameSpawner line above (NOTE: an error message appears after you exit the game)
	//gameSpawner = new Spawner();
}

World::~World()
{
	delete gameWeather;
	delete gameSpawner;
	delete gameWrath;
}

void World::backGroundSwap()
{
	switch (gameWeather->getTemperature())
	{
	case -1:
		dayBackground = *txtMap->at("coldDayBackground");
		eveningBackground = *txtMap->at("coldEveningBackground");
		nightBackground = *txtMap->at("coldNightBackground");
		break;
	case 0:
		dayBackground = *txtMap->at("regDayBackground");
		eveningBackground = *txtMap->at("regEveningBackground");
		nightBackground = *txtMap->at("regNightBackground");
		break;
	case 1:
		dayBackground = *txtMap->at("hotDayBackground");
		eveningBackground = *txtMap->at("hotEveningBackground");
		nightBackground = *txtMap->at("hotNightBackground");
		break;
	}
}

void World::handleInput()
{
	//Changes the background to be different based on the light sensor
	if(sf::Keyboard::isKeyPressed(dayButton))
	{
		background = sf::Sprite(dayBackground);
	}
	if(sf::Keyboard::isKeyPressed(eveningButton))
	{
		background = sf::Sprite(eveningBackground);
	}
	if(sf::Keyboard::isKeyPressed(nightButton))
	{
		background = sf::Sprite(nightBackground);
	}

	gameWeather->handleInput();

	gameWrath->handleInput();
}

void World::update(float deltaTime)
{
	gameWeather->update(deltaTime);
	gameWrath->getWeather(gameWeather->getWeather());
	gameSpawner->update(deltaTime);

	gameWrath->update(deltaTime);
	if(gameWrath->checkWrathing())
	{
		std::cout << gameWrath->getWrathDmg() << std::endl;
		gameSpawner->spreadWrathDmg(gameWrath->getWrathDmg());
	}

	if(lastTemp != gameWeather->getTemperature())
	{
		backGroundSwap();
		lastTemp = gameWeather->getTemperature();
	}
}

void World::draw(sf::RenderWindow* w)
{
	w->draw(background);
	gameSpawner->draw(w);
	gameWeather->draw(w);
	gameWrath->draw(w);
}

