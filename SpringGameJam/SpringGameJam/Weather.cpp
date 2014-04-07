#include "Weather.h"

Weather::Weather()
	:temperature(0), moisture(0),
	time(0),
	rainSystem(ParticleSystem("RainDrop", 500)),
	heavyRain(600), lightRain(150), noRain(0),
	//clouds(new sf::Sprite((*txtMap->at("Clouds")))),
	darkness(new sf::Sprite((*txtMap->at("Darkness"))))
{

}

Weather::~Weather()
{
	//delete clouds;
	delete darkness;
}

void Weather::handleInput()
{
	//Changes the tempurature based off of the turn sensor
	if(sf::Keyboard::isKeyPressed(hotButton))
	{
		temperature = -1;
	}
	if(sf::Keyboard::isKeyPressed(mildButton))
	{
		temperature = 0;
	}
	if(sf::Keyboard::isKeyPressed(coldButton))
	{
		temperature = 1;
	}

	//Changes the moisture based off of the turn sensor
	if(sf::Keyboard::isKeyPressed(dryButton))
	{
		moisture = -1;
	}
	if(sf::Keyboard::isKeyPressed(pleasentButton))
	{
		moisture = 0;
	}
	if(sf::Keyboard::isKeyPressed(wetButton))
	{
		moisture = 1;
	}

}

void Weather::update(float deltaTime)
{
	//checks the weather vars and
	//sets the weather var
	
	//hot and wet
	if(temperature > 0 && moisture > 0)
	{
		weatherState = 0;

		rainSystem.changeTexture("RainDrop");
		rainSystem.changeDensity(2);
		darkness->setColor(sf::Color(255,255,255,1000));

	}
	//hot and dry
	else if(temperature > 0 && moisture < 0)
	{
		weatherState = 1;

		rainSystem.changeDensity(0);
		rainSystem.clearSystem();
		darkness->setColor(sf::Color(255,255,255,0));

	}
	//hot and pleasent
	else if(temperature > 0 && moisture == 0)
	{
		weatherState = 2;

		rainSystem.changeTexture("RainDrop");
		rainSystem.changeDensity(1);
		darkness->setColor(sf::Color(255,255,255,50));

	}
	//cold and dry
	else if(temperature < 0 && moisture < 0)
	{
		weatherState = 3;

		rainSystem.changeDensity(0);
		rainSystem.clearSystem();
		darkness->setColor(sf::Color(255,255,255,0));

	}
	//cold and wet
	else if(temperature < 0 && moisture > 0)
	{
		weatherState = 4;

		rainSystem.changeTexture("Snow");
		rainSystem.changeDensity(2);
		darkness->setColor(sf::Color(255,255,255,1000));

	}
	//cold and pleasent
	else if(temperature < 0 && moisture == 0)
	{
		weatherState = 5;

		rainSystem.changeTexture("Snow");
		rainSystem.changeDensity(1);
		darkness->setColor(sf::Color(255,255,255,50));

	}
	//mild and pleasent
	else if(temperature == 0 && moisture == 0)
	{
		weatherState = 6;

		rainSystem.changeTexture("RainDrop");
		rainSystem.changeDensity(1);
		darkness->setColor(sf::Color(255,255,255,50));

	}
	//mild and wet
	else if(temperature == 0 && moisture > 0)
	{
		weatherState = 7;

		rainSystem.changeTexture("RainDrop");
		rainSystem.changeDensity(2);
		darkness->setColor(sf::Color(255,255,255,1000));

	}
	//mild and dry
	else if(temperature == 0 && moisture < 0)
	{
		weatherState = 8;

		rainSystem.changeDensity(0);
		rainSystem.clearSystem();
		darkness->setColor(sf::Color(255,255,255,0));

	}
	//error: temp and moisture outside normal paramaters
	else
	{
		weatherState = 9;
	}

	rainSystem.update(deltaTime);
}

void Weather::draw(sf::RenderWindow* w)
{
	w->draw(*darkness);
	rainSystem.draw(w);
	//w->draw(*clouds);
}

//****getters****

int Weather::getMoisture()
{
	return moisture;
}

int Weather::getTemperature()
{
	return temperature;
}

int Weather::getTime()
{
	return time;
}

//****setters****

void Weather::setMoisture(int newMoist)
{
	moisture = newMoist;
}

void Weather::setTemperature(int newTemp)
{
	temperature = newTemp;
}

void Weather::setTime(int newTime)
{
	time = newTime;
}

int Weather::getWeather()
{
	return weatherState;
}


