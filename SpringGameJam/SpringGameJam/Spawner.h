
//KTZ was here...
//4:42pm: defined spawner as a class, gave it some methods and variables
//7:44pm: defined constructor and destructor
//4-6-14, 12:33pm: made listOfAlivePeople vector public.
#ifndef SPAWNER_H
#define SPAWNER_H

#include "Entity.h"
#include "BaseNPC.h"
#include "Globals.h"
#include "Weather.h"
//#include <vector>

class Spawner : public Entity
{
public:
	Spawner();
	~Spawner();
	void draw(sf::RenderWindow* w);
	void update(float deltaTime);

	void changeState(Weather weather);
	void spawnPeople(float deltaTime);
	void createPeople();
	//std::vector<BaseNPC*> listOfAlivePeople;
private:
	BaseNPC peopleMaker;
	int peopleCounter;
	int currentState;
	sf::Sprite hut;
	bool fire;
	bool cold;
	bool hot;
	bool wet;
	sf::Time spawnTimer;
};

#endif //SPAWNER_H
