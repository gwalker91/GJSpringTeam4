
//KTZ was here...
//4:43pm: a lot of work still needs to be done for defining functions
//8:26pm: createPeople and spawnPeople need some work done.
//finished, for now, the constructor and destructor
//4-6-14, 12:37pm: fixed constructor and destructor.
//some progress made with spawnPeople, need to know how to spawn them.
#include "Spawner.h"

Spawner::Spawner() : spawnTimer(sf::seconds(0.0f)), peopleCounter(0)
{
	//allocate x amount of people from list. do not allocate more than i people.
	for(int i = 0; i < NUM_OF_PEOPLE; i++)
	{
		//need to modify this function with boolean values
		peopleMaker.listOfPeople.push_back(new BaseNPC());
		num_of_alive_people++;
	}
}

Spawner::~Spawner()
{
	//deallocate x amount of people from list. do not deallocate more than i people.
	for(int i = 0; i < NUM_OF_PEOPLE; i++)
		delete peopleMaker.listOfPeople[i];
}

void Spawner::draw(sf::RenderWindow* w)
{

}

void Spawner::update(float deltaTime)
{
	if(num_of_alive_people < NUM_OF_PEOPLE)
		createPeople();
}

//maybe the spawner can be covered in snow for cold temperatures, or look wet when its wet, etc.
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

//as long as there are less than x active people, keep running.
void Spawner::spawnPeople(float deltaTime)
{
	//here, we'll pop people out of the spawner and into the open world to wonder about.
	//every x amount of seconds, we will spawn new people from the list (the list will be
	//repopulated).
	spawnTimer = spawnTimer + sf::seconds(deltaTime);
	if(spawnTimer > sf::seconds(2.5f))
	{
		spawnTimer = sf::seconds(0.0f);
		for(unsigned int i = 0; i < peopleMaker.listOfPeople.size(); i++)
		{
			if(!peopleMaker.listOfPeople[i]->isActive)
			{
				//spawn npc, then break out of loop
				peopleMaker.listOfPeople[i]->isActive = true;
				peopleMaker.listOfPeople[i]->setPosition();
				peopleMaker.listOfPeople.erase(peopleMaker.listOfPeople.begin() + i);
				num_of_active_people++;
				break;
			}
			//otherwise keep searching for an inactive npc
		}
	}
}

//as long as there are less than x alive people, keep running, otherwise, stop
void Spawner::createPeople()
{
	//here, we'll make new people ready to be spawned.
	peopleMaker.listOfPeople.push_back(new BaseNPC());
	num_of_alive_people++;
}
