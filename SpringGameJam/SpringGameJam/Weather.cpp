#include "Weather.h"

Weather::Weather()
{
	temperature = 0;
	moisture = 0;
	time = 0;
}

Weather::~Weather()
{

}

void Weather::update(float deltaTime)
{
	//checks the weather vars and
	//sets the weather var
	
	//hot and wet
	if(temperature > 0 && moisture > 0)
	{

	}
	//hot and dry
	else if(temperature > 0 && moisture < 0)
	{

	}
	//hot and pleasent
	else if(temperature > 0 && moisture == 0)
	{

	}
	//cold and dry
	else if(temperature < 0 && moisture < 0)
	{

	}
	//cold and wet
	else if(temperature < 0 && moisture > 0)
	{

	}
	//cold and pleasent
	else if(temperature < 0 && moisture == 0)
	{

	}
	//mild and pleasent
	else if(temperature == 0 && moisture == 0)
	{

	}
	//mild and wet
	else if(temperature == 0 && moisture > 0)
	{

	}
	//mild and dry
	else if(temperature == 0 && moisture < 0)
	{

	}
	//error: temp and moisture outside normal paramaters
	else
	{

	}
}

void Weather::handleInput()
{
	//handle dat input
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

