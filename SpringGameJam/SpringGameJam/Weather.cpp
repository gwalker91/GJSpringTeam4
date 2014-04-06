#include "Weather.h"

Weather::Weather()
	:temperature(0), moisture(0),
	time(0),
	rainSystem(ParticleSystem("RainDrop", 500)),
	heavyRain(600), lightRain(150), noRain(0)
{

}

Weather::~Weather()
{

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
		//rainSystem.changeNumParticles(heavyRain);
		rainSystem.changeTexture("RainDrop");
		rainSystem.changeDensity(2);
		//std::cout << "Hot and Wet" << std::endl;
	}
	//hot and dry
	else if(temperature > 0 && moisture < 0)
	{
		weatherState = 1;
		//rainSystem.changeNumParticles(noRain);
		rainSystem.changeDensity(0);
		rainSystem.clearSystem();
		//std::cout << "hot and dry" << std::endl;
	}
	//hot and pleasent
	else if(temperature > 0 && moisture == 0)
	{
		weatherState = 2;
		//rainSystem.changeNumParticles(lightRain);
		rainSystem.changeTexture("RainDrop");
		rainSystem.changeDensity(1);
		//std::cout << "hot and pleasent" << std::endl;
	}
	//cold and dry
	else if(temperature < 0 && moisture < 0)
	{
		weatherState = 3;
		//rainSystem.changeNumParticles(noRain);
		rainSystem.changeDensity(0);
		rainSystem.clearSystem();
		//std::cout << "cold and dry" << std::endl;
	}
	//cold and wet
	else if(temperature < 0 && moisture > 0)
	{
		weatherState = 4;
		//rainSystem.changeNumParticles(heavyRain);
		rainSystem.changeTexture("Snow");
		rainSystem.changeDensity(2);
		//std::cout << "cold and wet" << std::endl;
	}
	//cold and pleasent
	else if(temperature < 0 && moisture == 0)
	{
		weatherState = 5;
		//rainSystem.changeNumParticles(lightRain);
		rainSystem.changeTexture("Snow");
		rainSystem.changeDensity(1);
		//std::cout << "cold and pleasent" << std::endl;
	}
	//mild and pleasent
	else if(temperature == 0 && moisture == 0)
	{
		weatherState = 6;
		//rainSystem.changeNumParticles(lightRain);
		rainSystem.changeTexture("RainDrop");
		rainSystem.changeDensity(1);
		//std::cout << "mild and pleasent" << std::endl;
	}
	//mild and wet
	else if(temperature == 0 && moisture > 0)
	{
		weatherState = 7;
		//rainSystem.changeNumParticles(heavyRain);
		rainSystem.changeTexture("RainDrop");
		rainSystem.changeDensity(2);
		//std::cout << "mild and wet" << std::endl;
	}
	//mild and dry
	else if(temperature == 0 && moisture < 0)
	{
		weatherState = 8;
		//rainSystem.changeNumParticles(noRain);
		rainSystem.changeDensity(0);
		rainSystem.clearSystem();

		//std::cout << "mild and dry" << std::endl;
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
	rainSystem.draw(w);
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

