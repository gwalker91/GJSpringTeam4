
//KTZ was here...
//defined the functions for BaseNPC
//for all functions needing to animate, we still need images to load
#include "BaseNPC.h"

BaseNPC::BaseNPC() : HP(5 + (rand() % 16)), isDead(false), onFire(false), walkingSpeed(1 + float(rand() % 5)), 
					 isChangingDirection(false)
{}

BaseNPC::~BaseNPC()
{}

void BaseNPC::walk()
{
	//play walking animation
	walkingSpeed = walkingSpeed + gravity;
}

//TODO: implement falling speed

void BaseNPC::setOnFire()
{
	//play animation with npc on fire
	//decrease their HP over time
}

void BaseNPC::setIsCold()
{
	//play animation of npc freezing
	walkingSpeed /= 2;
	//decrease their HP over time
}

void BaseNPC::setIsHot()
{
	//play animation of npc freezing
	walkingSpeed /= 2;
	//decrease their HP over time
}

void BaseNPC::setIsDead()
{
	//play dead animation once and let it lie there for a few seconds before deallocation
	walkingSpeed *= 0;
}

void BaseNPC::changeState(/*weather parameter(s)*/)
{
	//need to be able to handle different cases of weather
	//weather will need to be completed before going further with this
	/*switch(0)
	{
	default:
	}*/
}

void BaseNPC::setPanicking()
{
	walkingSpeed *= 2;
	//I would like to try to get the npc to walk the opposite direction from where the player is
	changeDirection();
}

void BaseNPC::damageHP(int damage)
{
	HP -= damage;
}

//I think there may be a simpler way to change direction than what I have
int BaseNPC::changeDirection()
{
	if(isChangingDirection)
		return -1;
	else
		return 1;
}
