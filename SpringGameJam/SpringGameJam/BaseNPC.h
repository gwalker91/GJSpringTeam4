
//KTZ was here...
//Included falling speed, changed walking speed
//into two different variables: maxspeed and currentspeed
//included a private method to let npc's speed change.
//4-6-14, 3:00pm: 95% finished with everything here, just need some help going over
//code, put in finishing touches and working on update and (maybe) draw functions.
//4-7-14, 9:46am: commenting a few functions and variables as we probably don't have
//time to finish these features.
#ifndef BASENPC_H
#define BASENPC_H


#include "Entity.h"
#include "Globals.h"
#include "Weather.h"
#include <random>
#include <vector>

class BaseNPC : public Entity
{
public:
	BaseNPC();
	BaseNPC(sf::Sprite human, sf::Vector2f initPosition, bool hot, bool cold);
	~BaseNPC();
	void draw(sf::RenderWindow* w);
	void update(float deltaTime);
	void updateWalkSprite();
	void despawnTimer(float deltaTime);

	//NPC Behavior
	virtual void walk();
	virtual void verticalMove();

	//will play the animation on the npc
	virtual void setOnFire(float deltaTime);
	virtual void setIsCold(float deltaTime);
	virtual void setIsHot(float deltaTime);
	//virtual void setIsWet(float deltaTime);

	//a universal state changer based on current state of game weather
	virtual void changeState(Weather weather);

	virtual void setIsDead();
	virtual void setPanicking();

	virtual void damageHP(int damage);
	virtual bool groundCollision();

	virtual void setPosition();

	//NPC states variables - also for playing their respective animations
	//game elements should be able to access an npc's current state and change it, like weather
	bool onFire;
	bool isCold;	//based on current state of weather
	bool isHot;		//based on current state of weather
	//bool isWet;		//based on current state of weather
	bool isDead;
	bool panicking;
	bool isActive;

	//still need to discuss what to do with the two meters mentioned.
	//I'm disabling terror and respect at this point
	//int terror;
	//int respect;

	//for spawner to have access to
	//std::vector<BaseNPC*> listOfPeople;
private:
	int HP; //health points
	float maxSpeed;
	float currentSpeed;
	bool isChangingDirection;
	int changeDirection();
	float changeSpeed();
	float changeFallSpeed();
	float fallingSpeed;
	sf::Sprite Human;
	sf::Vector2f position;
	sf::Time DOT; //moar dotz NOAW! (damage over time)
	sf::Time despawner;
	sf::Time spriteSwap;
	int row;
	int col;
};

#endif //BASENPC_H
