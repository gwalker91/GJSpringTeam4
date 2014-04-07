
//KTZ was here...
//4:43pm: a lot of work still needs to be done for defining functions
//8:26pm: createPeople and spawnPeople need some work done.
//finished, for now, the constructor and destructor
//4-6-14, 12:37pm: fixed constructor and destructor.
//some progress made with spawnPeople, need to know how to spawn them.
//3:00pm: 95% finished with everything here, just need some help going over
//code, put in finishing touches and working on update and (maybe) draw functions.
#include "Spawner.h"

Spawner::Spawner(sf::Sprite hut, sf::Vector2f initPosition) 
	: spawnTimer(sf::seconds(0.0f)), village(5), town(20), city(50),
	  hutImage(hut), position(initPosition), wrathApplied(false)
{
	hutImage.setPosition(position);
	//allocate x amount of people from list. do not allocate more than i people.
	for(int i = 0; i < village; i++)
	{
		//need to modify this function with boolean values
		//peopleMaker.listOfPeople.push_back(new BaseNPC(sf::Sprite(*txtMap->at("NormalHuman")), sf::Vector2f(400.0f, 400.0f), hot, cold));
		listOfPeople.push_back(new BaseNPC(sf::Sprite(*txtMap->at("NormalHuman")), sf::Vector2f(400.0f, 400.0f), hot, cold));
		num_of_alive_people++;
	}
}

Spawner::~Spawner()
{
	//deallocate x amount of people from list. do not deallocate more than i people.
	/*
	if(peopleMaker.listOfPeople.size() > 0)
	{
		for(int i = 0; i < NUM_OF_PEOPLE; i++)
			delete peopleMaker.listOfPeople[i];
	}
	*/
}

void Spawner::draw(sf::RenderWindow* w)
{
	w->draw(hutImage);
	//call the draw method for npcs in here
	for(int i = 0; i < listOfPeople.size(); i++)
	{
		if(listOfPeople.at(i)->isActive)
		{
			//std::cout << listOfPeople.at(i)->isActive << std::endl;
			listOfPeople.at(i)->draw(w);
		}
	}
}

void Spawner::update(float deltaTime)
{
	if(num_of_alive_people < NUM_OF_PEOPLE)
		createPeople();

	if(num_of_active_people < listOfPeople.size())
		spawnPeople(deltaTime);

	if(listOfPeople.size() > 0)
	{
		for(int i = 0; i < listOfPeople.size(); i++)
		{
			if(!listOfPeople.at(i)->isDead)
				listOfPeople.at(i)->update(deltaTime);
			else
				listOfPeople.erase(listOfPeople.begin() + i);
		}
	}
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

//as long as there are less than x active people, keep running, otherwise, stop
void Spawner::spawnPeople(float deltaTime)
{
	//here, we'll pop people out of the spawner and into the open world to wonder about.
	//every x amount of seconds, we will spawn new people from the list (the list will be
	//repopulated).
	spawnTimer = spawnTimer + sf::seconds(deltaTime);
	//std::cout << spawnTimer.asMilliseconds() << std::endl;
	if(spawnTimer > sf::seconds(2.5f))
	{

		spawnTimer = sf::seconds(0.0f);
		for(unsigned int i = 0; i < listOfPeople.size(); i++)
		{
			if(!listOfPeople.at(i)->isActive)
			{
				//spawn npc, then break out of loop
				listOfPeople.at(i)->isActive = true;
				listOfPeople.at(i)->setPosition();
				num_of_active_people++;
				std::cout << "Spawned" << std::endl;
				std::cout << num_of_active_people << std::endl;
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
	listOfPeople.push_back(new BaseNPC(Human, position, hot, cold));
	num_of_alive_people++;
	std::cout << "num_people: " << num_of_alive_people << std::endl;
}

bool Spawner::hasWrathApplied()
{
	return wrathApplied;
}

void Spawner::spreadWrathDmg(float wrathDmg)
{
	//std::cout << wrathApplied << std::endl;
	if(!hasWrathApplied())
	{
		int finalDmg = wrathDmg;
		wrathApplied = true;
		for(int i = 0; i < listOfPeople.size(); i++)
		{
			listOfPeople.at(i)->damageHP(finalDmg);
		}
	}
}
