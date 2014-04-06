
//KTZ was here...
//defined the functions for BaseNPC
//for all functions needing to animate, we still need images to load
//4:41pm:almost done now, just need to finish making sure npcs do not fall through the world
//and double check everything
#include "BaseNPC.h"

//TODO: still need to load image onto BaseNPC.
BaseNPC::BaseNPC() : HP(5 + (rand() % 16)), isDead(false), onFire(false), maxSpeed(1 + float(rand() % 5)), 
	currentSpeed(maxSpeed), fallingSpeed(gravity), isChangingDirection(false), DOT(sf::seconds(0.0f))
{}

BaseNPC::~BaseNPC()
{
	
}

void BaseNPC::update(float deltaTime)
{}

void BaseNPC::walk()
{
	//play walking animation
	//move around using current speed
	//at random times, the npc's direction will change
	if(rand() % 1000 > 900)
		isChangingDirection = true;
	currentSpeed *= changeDirection();
	Human.move(sf::Vector2f(Human.getPosition().x + currentSpeed, Human.getPosition().y));
	
}

//depending on gravity, the npc will either be constantly rising or falling
void BaseNPC::verticalMove()
{
	if(!groundCollision())
		Human.move(sf::Vector2f(Human.getPosition().x, Human.getPosition().y + fallingSpeed));
}

bool BaseNPC::groundCollision()
{
	//need to calculate collision between ground and person.
	return true;
}

//This method should only run if the npc is on fire
void BaseNPC::setOnFire(float deltaTime)
{
	//play animation with npc on fire
	//decrease their HP over time
	DOT = DOT + sf::seconds(deltaTime);
	if(DOT > sf::seconds(1.0f))
	{
		DOT = sf::seconds(0.0f);
		damageHP(2);
	}
}

void BaseNPC::setIsCold(float deltaTime)
{
	//play animation of npc freezing
	currentSpeed = changeSpeed(gravity)/2;
	//decrease their HP over time
	DOT = DOT + sf::seconds(deltaTime);
	if(DOT > sf::seconds(1.0f))
	{
		DOT = sf::seconds(0.0f);
		damageHP(2);
	}
}

void BaseNPC::setIsHot(float deltaTime)
{
	//play animation of npc sweaty
	currentSpeed = changeSpeed(gravity)/2;
	//decrease their HP over time
	DOT = DOT + sf::seconds(deltaTime);
	if(DOT > sf::seconds(1.0f))
	{
		DOT = sf::seconds(0.0f);
		damageHP(2);
	}
}

void BaseNPC::setIsWet(float deltaTime)
{
	//play animation of npc wet
}

void BaseNPC::setIsDead()
{
	//play dead animation once and let it lie there for a few seconds before deallocation
	currentSpeed *= 0;
}

void BaseNPC::changeState(Weather weather)
{
	//need to be able to handle different cases of weather
	if(weather.getTemperature() > 0 && weather.getMoisture() > 0)
	{
		isCold = false;
		isHot = false;
		isWet = true;
	}
	//hot and dry
	else if(weather.getTemperature() > 0 && weather.getMoisture() < 0)
	{
		isCold = false;
		isHot = true;
		isWet = false;
	}
	//hot and pleasent
	else if(weather.getTemperature() > 0 && weather.getMoisture() == 0)
	{
		isCold = false;
		isHot = true;
		isWet = false;
	}
	//cold and dry
	else if(weather.getTemperature() < 0 && weather.getMoisture() < 0)
	{
		isCold = true;
		isHot = false;
		isWet = false;
	}
	//cold and wet
	else if(weather.getTemperature() < 0 && weather.getMoisture() > 0)
	{
		isCold = true;
		isHot = false;
		isWet = false;
	}
	//cold and pleasent
	else if(weather.getTemperature() < 0 && weather.getMoisture() == 0)
	{
		isCold = true;
		isHot = false;
		isWet = false;
	}
	//mild and pleasent
	else if(weather.getTemperature() == 0 && weather.getMoisture() == 0)
	{
		isCold = false;
		isHot = false;
		isWet = false;
	}
	//mild and wet
	else if(weather.getTemperature() == 0 && weather.getMoisture() > 0)
	{
		isCold = false;
		isHot = false;
		isWet = true;
	}
	//mild and dry
	else if(weather.getTemperature() == 0 && weather.getMoisture() < 0)
	{
		isCold = false;
		isHot = false;
		isWet = false;
	}
}

void BaseNPC::setPanicking()
{
	currentSpeed = changeSpeed(gravity) * 2;
	//I would like to try to get the npc to walk the opposite direction from where the player is
	changeDirection();
}

void BaseNPC::damageHP(int damage)
{
	HP -= damage;
}

int BaseNPC::changeDirection()
{
	if(isChangingDirection)
	{
		isChangingDirection = false;
		return -1;
	}
	else
		return 1;
}

float BaseNPC::changeSpeed(int gravityInfluence)
{
	//run through this function once at initial start and everytime gravity is changed
	return maxSpeed - gravity;
}

float BaseNPC::changeFallSpeed(int gravityInfluence)
{
	//run through this function once at initial start and everytime gravity is changed
	return fallingSpeed = gravity;
}
