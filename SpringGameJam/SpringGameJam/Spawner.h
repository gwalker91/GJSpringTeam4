//KTZ was here...
//4:42pm: defined spawner as a class, gave it some methods and variables
//7:44pm: defined constructor and destructor
#ifndef SPAWNER_H
#define SPAWNER_H

#include "BaseNPC.h"
#include "Globals.h"
#include "Weather.h"
#include <vector>

class Spawner : public Entity
{
public:
	Spawner();
	~Spawner();
	void update(float deltaTime);

	void changeState(Weather weather);
	void spawnPeople();
private:
	int currentState;
	sf::Sprite hut;
	std::vector<BaseNPC*> listOfPeople[5];
	bool fire;
	bool cold;
	bool hot;
	bool wet;
};

#endif //SPAWNER_H