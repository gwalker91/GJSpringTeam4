
//KTZ was here...
//4:42pm: defined spawner as a class, gave it some methods and variables
#ifndef SPAWNER_H
#define SPAWNER_H

#include "BaseNPC.h"
#include <vector>

class Spawner : public Entity
{
public:
	Spawner();
	~Spawner();
	void update(float deltaTime);
	void draw(sf::RenderWindow w);

	void changeState(/*weather parameters*/);
	void spawnPeople();
private:
	sf::Sprite hut;
	std::vector<BaseNPC> listOfPeople;
};

#endif //SPAWNER_H