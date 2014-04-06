#include "Weather.h"

Weather::Weather()
	:temperature(0), moisture(0),
	time(0),
	rainSystem(ParticleSystem("RainDrop", 0)),
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
		//m.setColor(sf::Color(255,255,255,200));
		//temp.setColor(sf::Color(255,255,255,120));
		rainSystem.changeNumParticles(heavyRain);
		std::cout << "Hot and Wet" << std::endl;
	}
	//hot and dry
	else if(temperature > 0 && moisture < 0)
	{
		weatherState = 1;
		//m.setColor(sf::Color(255,255,255,0));
		//temp.setColor(sf::Color(255,255,255,120));
		rainSystem.changeNumParticles(noRain);
		rainSystem.clearSystem();
		std::cout << "hot and dry" << std::endl;
	}
	//hot and pleasent
	else if(temperature > 0 && moisture == 0)
	{
		weatherState = 2;
		//m.setColor(sf::Color(255,255,255,50));
		//temp.setColor(sf::Color(255,255,255,120));
		rainSystem.changeNumParticles(lightRain);
		std::cout << "hot and pleasent" << std::endl;
	}
	//cold and dry
	else if(temperature < 0 && moisture < 0)
	{
		weatherState = 3;
		//m.setColor(sf::Color(255,255,255,0));
		rainSystem.changeNumParticles(noRain);
		rainSystem.clearSystem();
		std::cout << "cold and dry" << std::endl;
	}
	//cold and wet
	else if(temperature < 0 && moisture > 0)
	{
		weatherState = 4;
		//m.setColor(sf::Color(255,255,255,200));
		rainSystem.changeNumParticles(heavyRain);
		std::cout << "cold and wet" << std::endl;
	}
	//cold and pleasent
	else if(temperature < 0 && moisture == 0)
	{
		weatherState = 5;
		//m.setColor(sf::Color(255,255,255,50));
		rainSystem.changeNumParticles(lightRain);
		std::cout << "cold and pleasent" << std::endl;
	}
	//mild and pleasent
	else if(temperature == 0 && moisture == 0)
	{
		weatherState = 6;
		//m.setColor(sf::Color(255,255,255,50));
		//temp.setColor(sf::Color(255,255,255,50));
		rainSystem.changeNumParticles(lightRain);
		std::cout << "mild and pleasent" << std::endl;
	}
	//mild and wet
	else if(temperature == 0 && moisture > 0)
	{
		weatherState = 7;
		//m.setColor(sf::Color(255,255,255,200));
		//temp.setColor(sf::Color(255,255,255,50));
		rainSystem.changeNumParticles(heavyRain);
		std::cout << "mild and wet" << std::endl;
	}
	//mild and dry
	else if(temperature == 0 && moisture < 0)
	{
		weatherState = 8;
		//m.setColor(sf::Color(255,255,255,0));
		//temp.setColor(sf::Color(255,255,255,50));
		rainSystem.changeNumParticles(noRain);
		rainSystem.clearSystem();
		std::cout << "mild and dry" << std::endl;
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

