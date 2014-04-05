
//KTZ was here...
//made BaseNPC class
#ifndef BASENPC_H
#define BASENPC_H

#include "Entity.h"
#include "Globals.h"
#include <random>

class BaseNPC : public Entity
{
public:
	BaseNPC();
	~BaseNPC();
	void update(float deltaTime);
	void draw(sf::RenderWindow w);

	//NPC Behavior
	virtual void walk();

	//will play the animation on the npc
	virtual void setOnFire();
	virtual void setIsCold();
	virtual void setIsHot();

	//a universal state changer based on current state of game weather or their health to change their current state...
	virtual void changeState(/*weather parameter(s)*/);

	virtual void setIsDead();
	virtual void setPanicking();

	virtual void damageHP(int damage);

	//NPC states variables - also for playing their respective animations
	//game elements should be able to access an npc's current state and change it, like weather
	bool onFire;
	bool isCold;	//based on current state of weather
	bool isHot;		//based on current state of weather
	bool isDead;
	bool panicking;

	//still need to discuss what to do with the two meters discussed.
	int terror;
	int respect;

private:
	int HP; //health points
	float walkingSpeed;
	bool isChangingDirection;
	int changeDirection();
	sf::Sprite tinyHumanBeing;
};

#endif //BASENPC_H