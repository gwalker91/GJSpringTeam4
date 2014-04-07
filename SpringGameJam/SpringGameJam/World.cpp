
#include "World.h"

World::World()
	:background((*txtMap->at("regDayBackground"))),
	gameWeather(new Weather()),
	gameWrath(new Wrath()),
	gameSpawner(new Spawner(sf::Sprite(*txtMap->at("Hut")), sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT*0.60))),
	lastTemp(0),
	timeOfDay(0),
	saved(false)
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
		if(timeOfDay == 0)
		{
			background = sf::Sprite(*txtMap->at("coldDayBackground"));
		}
		if(timeOfDay == 1)
		{
			background = sf::Sprite(*txtMap->at("coldEveBackground"));
		}
		if(timeOfDay == 2)
		{
			background = sf::Sprite(*txtMap->at("coldNightBackground"));
		}
		break;
	case 0:
		if(timeOfDay == 0)
		{
			background = sf::Sprite(*txtMap->at("regDayBackground"));
		}
		if(timeOfDay == 1)
		{
			background = sf::Sprite(*txtMap->at("regEveBackground"));
		}
		if(timeOfDay == 2)
		{
			background = sf::Sprite(*txtMap->at("regNightBackground"));
		}
		break;
	case 1:
		if(timeOfDay == 0)
		{
			background = sf::Sprite(*txtMap->at("hotDayBackground"));
		}
		if(timeOfDay == 1)
		{
			background = sf::Sprite(*txtMap->at("hotEveBackground"));
		}
		if(timeOfDay == 2)
		{
			background = sf::Sprite(*txtMap->at("hotNightBackground"));
		}
		break;
	}
}

void World::handleInput()
{
	if(!saved)
	{
		if(sf::Keyboard::isKeyPressed(saveButton))
		{
			saved = true;
		}
		//Changes the background to be different based on the light sensor
		if(sf::Keyboard::isKeyPressed(dayButton))
		{
			timeOfDay = 0;
		}
		if(sf::Keyboard::isKeyPressed(eveningButton))
		{
			timeOfDay = 1;
		}
		if(sf::Keyboard::isKeyPressed(nightButton))
		{
			timeOfDay = 2;
		}

		gameWeather->handleInput();
	}
	else
	{
		if(sf::Keyboard::isKeyPressed(saveButton))
		{
			saved = false;
		}
	}

	gameWrath->handleInput();
}

void World::update(float deltaTime)
{
	gameWeather->update(deltaTime);
	gameWrath->getWeather(gameWeather->getWeather());
	std::cout << gameWeather->getWeather() << std::endl;
	gameSpawner->update(deltaTime);

	gameWrath->update(deltaTime);
	if(gameWrath->checkWrathing())
	{
		std::cout << gameWrath->getWrathDmg() << std::endl;
		gameSpawner->spreadWrathDmg(gameWrath->getWrathDmg());
	}

	backGroundSwap();

}

void World::draw(sf::RenderWindow* w)
{
	w->draw(background);
	gameSpawner->draw(w);
	gameWeather->draw(w);
	gameWrath->draw(w);
}

