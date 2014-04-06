//KTZ was here...
//Included falling speed, changed walking speed
//into two different variables: maxspeed and currentspeed
//included a private method to let npc's speed change.
#ifndef BASENPC_H
#define BASENPC_H

#include "Entity.h"
#include "Globals.h"
#include "Weather.h"
#include <random>

class BaseNPC : public Entity
{
public:
BaseNPC();
~BaseNPC();
void update(float deltaTime);

//NPC Behavior
virtual void walk();
virtual void verticalMove();

//will play the animation on the npc
virtual void setOnFire(float deltaTime);
virtual void setIsCold(float deltaTime);
virtual void setIsHot(float deltaTime);
virtual void setIsWet(float deltaTime);

//a universal state changer based on current state of game weather
virtual void changeState(Weather weather);

virtual void setIsDead();
virtual void setPanicking();

virtual void damageHP(int damage);
virtual bool groundCollision();

//NPC states variables - also for playing their respective animations
//game elements should be able to access an npc's current state and change it, like weather
bool onFire;
bool isCold;	//based on current state of weather
bool isHot;	//based on current state of weather
bool isWet;	//based on current state of weather
bool isDead;
bool panicking;

//still need to discuss what to do with the two meters mentioned.
int terror;
int respect;

private:
int HP; //health points
float maxSpeed;
float currentSpeed;
bool isChangingDirection;
int changeDirection();
float changeSpeed(int gravityInfluence);
float changeFallSpeed(int gravityInfluence);
int fallingSpeed;
sf::Sprite Human;
sf::Time DOT; //moar dotz NOAW! (damage over time)
};

#endif //BASENPC_H