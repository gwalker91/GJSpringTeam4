
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
}

Spawner::~Spawner()
{

}

void Spawner::draw(sf::RenderWindow* w)
{
	w->draw(hutImage);
	for(int i = 0; i < listOfPeople.size(); i++)
	{
		listOfPeople.at(i)->draw(w);
	}
}

void Spawner::update(float deltaTime)
{
	if(listOfPeople.size() < NUM_OF_PEOPLE)
	{
		createPeople();
	}
	for(int i = 0; i < listOfPeople.size(); i++)
	{
		if(listOfPeople.at(i)->checkAlive())
			listOfPeople.at(i)->update(deltaTime);
		else
		{
			NPC* pointer = listOfPeople.at(i);
			listOfPeople.erase(listOfPeople.begin() + i);
			delete pointer;
		}
	}
}

//maybe the spawner can be covered in snow for cold temperatures, or look wet when its wet, etc.
void Spawner::checkState(int weather)
{
	for(int i = 0; i < listOfPeople.size(); i++)
	{
		listOfPeople.at(i)->checkWeather(weather);
	}
}

//as long as there are less than x active people, keep running, otherwise, stop
void Spawner::spawnPeople(float deltaTime)
{
	
}

//as long as there are less than x alive people, keep running, otherwise, stop
void Spawner::createPeople()
{
	listOfPeople.push_back(new NPC(sf::Vector2f(position.x, SCREEN_HEIGHT * 0.75f)));
}

bool Spawner::hasWrathApplied()
{
	return wrathApplied;
}

void Spawner::spreadWrathDmg(float wrathDmg)
{
	for(int i = 0; i < listOfPeople.size(); i++)
	{
		listOfPeople.at(i)->doDamage(wrathDmg, true);
	}
}
