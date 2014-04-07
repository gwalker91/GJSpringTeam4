
#include "World.h"

World::World()
	:background((*txtMap->at("DayBackground"))),
	gameWeather(new Weather()),
	gameWrath(new Wrath()),
	gameSpawner(new Spawner(sf::Sprite(*txtMap->at("Hut")), sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT*0.60))) 
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

void World::handleInput()
{
	//Changes the background to be different based on the light sensor
	if(sf::Keyboard::isKeyPressed(dayButton))
	{
		background = sf::Sprite((*txtMap->at("DayBackground")));
	}
	if(sf::Keyboard::isKeyPressed(eveningButton))
	{
		background = sf::Sprite((*txtMap->at("EveningBackGround")));
	}
	if(sf::Keyboard::isKeyPressed(nightButton))
	{
		background = sf::Sprite((*txtMap->at("NightBackground")));
	}

	gameWeather->handleInput();

	gameWrath->handleInput();
}

void World::update(float deltaTime)
{
	gameWeather->update(deltaTime);
	gameSpawner->update(deltaTime);

	gameWrath->update(deltaTime);
	if(gameWrath->checkWrathing())
	{
		std::cout << gameWrath->getWrathDmg() << std::endl;
		gameSpawner->spreadWrathDmg(gameWrath->getWrathDmg());
	}
}

void World::draw(sf::RenderWindow* w)
{
	w->draw(background);
	gameWeather->draw(w);
	gameSpawner->draw(w);
	gameWrath->draw(w);
}

