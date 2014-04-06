
//KTZ was here...
//4:42pm: defined spawner as a class, gave it some methods and variables
//7:44pm: defined constructor and destructor
//4-6-14, 12:33pm: made listOfAlivePeople vector public.
//3:00pm: 95% finished with everything here, just need some help going over
//code, put in finishing touches and working on update and (maybe) draw functions.
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
	Spawner(sf::Sprite hut, sf::Vector2f initPosition);
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
	sf::Sprite hutImage;
	sf::Sprite Human;
	sf::Vector2f position;
	bool fire;
	bool cold;
	bool hot;
	bool wet;
	sf::Time spawnTimer;
};

#endif //SPAWNER_H
