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
		weatherState = 0;
	}
	//hot and dry
	else if(temperature > 0 && moisture < 0)
	{
		weatherState = 1;
	}
	//hot and pleasent
	else if(temperature > 0 && moisture == 0)
	{
		weatherState = 2;
	}
	//cold and dry
	else if(temperature < 0 && moisture < 0)
	{
		weatherState = 3;
	}
	//cold and wet
	else if(temperature < 0 && moisture > 0)
	{
		weatherState = 4;
	}
	//cold and pleasent
	else if(temperature < 0 && moisture == 0)
	{
		weatherState = 5;
	}
	//mild and pleasent
	else if(temperature == 0 && moisture == 0)
	{
		weatherState = 6;
	}
	//mild and wet
	else if(temperature == 0 && moisture > 0)
	{
		weatherState = 7;
	}
	//mild and dry
	else if(temperature == 0 && moisture < 0)
	{
		weatherState = 8;
	}
	//error: temp and moisture outside normal paramaters
	else
	{
		weatherState = 9;
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

