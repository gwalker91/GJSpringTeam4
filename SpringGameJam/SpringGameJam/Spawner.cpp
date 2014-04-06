
//KTZ was here...
//4:43pm: a lot of work still needs to be done for defining functions
#include "Spawner.h"

Spawner::Spawner()
{
	//allocate x amount of people from list. do not allocate more than i people.
	for(int i = 0; i < NUM_OF_PEOPLE; i++)
	{
		listOfPeople[i].push_back(new BaseNPC());
	}
}

Spawner::~Spawner()
{
	//deallocate x amount of people from list. do not deallocate more than i people.
	for(int i = 0; i < NUM_OF_PEOPLE; i++)
		delete &listOfPeople[i];
}

void Spawner::changeState(Weather weather)
{
	//need to be able to handle different cases of weather
	if(weather.getTemperature() > 0 && weather.getMoisture() > 0)
	{
		cold = false;
		hot = false;
		wet = true;
	}
	//hot and dry
	else if(weather.getTemperature() > 0 && weather.getMoisture() < 0)
	{
		cold = false;
		hot = true;
		wet = false;
	}
	//hot and pleasent
	else if(weather.getTemperature() > 0 && weather.getMoisture() == 0)
	{
		cold = false;
		hot = true;
		wet = false;
	}
	//cold and dry
	else if(weather.getTemperature() < 0 && weather.getMoisture() < 0)
	{
		cold = true;
		hot = false;
		wet = false;
	}
	//cold and wet
	else if(weather.getTemperature() < 0 && weather.getMoisture() > 0)
	{
		cold = true;
		hot = false;
		wet = false;
	}
	//cold and pleasent
	else if(weather.getTemperature() < 0 && weather.getMoisture() == 0)
	{
		cold = true;
		hot = false;
		wet = false;
	}
	//mild and pleasent
	else if(weather.getTemperature() == 0 && weather.getMoisture() == 0)
	{
		cold = false;
		hot = false;
		wet = false;
	}
	//mild and wet
	else if(weather.getTemperature() == 0 && weather.getMoisture() > 0)
	{
		cold = false;
		hot = false;
		wet = true;
	}
	//mild and dry
	else if(weather.getTemperature() == 0 && weather.getMoisture() < 0)
	{
		cold = false;
		hot = false;
		wet = false;
	}
}

void Spawner::spawnPeople()
{
	
}