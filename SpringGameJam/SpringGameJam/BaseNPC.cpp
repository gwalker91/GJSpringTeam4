
//KTZ was here...
//defined the functions for BaseNPC
//for all functions needing to animate, we still need images to load
//4:41pm:almost done now, just need to finish making sure npcs do not fall through the world
//and double check everything
//3:00pm: 95% finished with everything here, just need some help going over
//code, put in finishing touches and working on update and (maybe) draw functions.
#include "BaseNPC.h"

BaseNPC::BaseNPC() 
{}

BaseNPC::BaseNPC(sf::Sprite human, sf::Vector2f initPosition, bool hot, bool cold) 
	: HP(5 + (rand() % MAX_HEALTH)), isDead(false), onFire(false), maxSpeed(1 + float(rand() % 2)), 
	  currentSpeed(maxSpeed), fallingSpeed(gravity), isChangingDirection(false), 
	  DOT(sf::seconds(0.0f)), despawner(sf::seconds(0.0f)), isActive(false), isHot(hot), 
	  isCold(cold), position(initPosition), Human(human), col(0), row(0), spriteSwap(sf::seconds(1.5f))
{
	//when inactive, we should probably put it off screen, then let the spawner "spawn" the npc.
	Human.setPosition(position);
}

BaseNPC::~BaseNPC()
{
	num_of_alive_people--;
	num_of_active_people--;
	//listOfPeople.erase(this);
}

void BaseNPC::draw(sf::RenderWindow* w)
{
	w->draw(Human);
}

void BaseNPC::update(float deltaTime)
{
	//this is where all the updates will occur, using all the defined functions below
	if(HP < 0)
		setIsDead();
	if(!isDead)
	{
		//TODO: getting the npc to appear on screen, walking about
		//need to be able to access weather as is
		//changeState(weather);
		changeSpeed();
		changeFallSpeed();
		walk();
		verticalMove();
		if(spriteSwap <= sf::seconds(0.0f))
		{
			spriteSwap = sf::seconds(1.5f);
			updateSprite();
		}
		//50x100
	}
	else
	{
		despawnTimer(deltaTime);
	}

}

void BaseNPC::updateSprite()
{
	col++;

	if(col == 3)
	{
		col = 0;
		row++;
		if(row = 4)
			row = 0;
	}
	Human.setTextureRect(sf::IntRect(col * 50, row * 100, 50, 100));
}

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

//run once npc is dead
void BaseNPC::despawnTimer(float deltaTimer)
{
	despawner = despawner + sf::seconds(deltaTimer);
	if(despawner > sf::seconds(3.0f))
		delete this;
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
	return Human.getPosition().y + fallingSpeed > SCREEN_HEIGHT * 0.75;
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
	currentSpeed = changeSpeed()/2;
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
	currentSpeed = changeSpeed()/2;
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
	isDead = true;
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

//if npc survives a direct hit from player, npc should panic in response
void BaseNPC::setPanicking()
{
	panicking = true;
	currentSpeed = changeSpeed() * 2;
	//I would like to try to get the npc to walk the opposite direction from where the player is (maybe not needed)
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

float BaseNPC::changeSpeed()
{
	//run through this function once at initial start and everytime gravity is changed
	return maxSpeed - gravity;
}

float BaseNPC::changeFallSpeed()
{
	//run through this function once at initial start and everytime gravity is changed
	return fallingSpeed = gravity;
}

//only call when npc is being spawned. should only be done once per spawn.
void BaseNPC::setPosition()
{
	Human.setPosition(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT * 0.5));
}
