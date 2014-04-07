
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
	: HP(MIN_HEALTH + (rand() % MAX_HEALTH)), isDead(false), onFire(false), maxSpeed(100), 
	  currentSpeed(maxSpeed), fallingSpeed(300), isChangingDirection(false), idling(true), 
	  DOT(0.0f), despawner(0.0f), isActive(true), isHot(hot), 
	  isCold(cold), position(initPosition), Human(human), col(0), row(0), spriteSwap(0.1f),
	  idleCols(4), walkingCols(5), dyingCols(4), totalCols(idleCols), timeToWalk(1.5f), randNum(0)
{
	//when inactive, we should probably put it off screen, then let the spawner "spawn" the npc.
	Human.setPosition(position);
	Human.setTextureRect(sf::IntRect(0, 0, 50, 100));

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
		spriteSwap -= deltaTime;
		//TODO: getting the npc to appear on screen, walking about
		//need to be able to access weather as is
		//changeState(weather);
		changeSpeed();
		changeFallSpeed();
		walk(deltaTime);
		verticalMove(deltaTime);
		if(spriteSwap <= 0.0f)
		{
			spriteSwap = 0.1f;
			updateWalkSprite();
		}
		//50x100
	}
	//else
	//{
	//	despawnTimer(deltaTime);
	//}


}

void BaseNPC::updateWalkSprite()
{
	col++;

	if(col == totalCols)
	{
		col = 0;
	}
	Human.setTextureRect(sf::IntRect(col * 50, row * 100, 50, 100));
}

void BaseNPC::walk(float deltaTime)
{
	//play walking animation
	//move around using current speed
	//at random times, the npc's direction will change
	timeToWalk -= deltaTime;
	if(timeToWalk <= 0)
	{
		 randNum= rand() % 1000;
		 timeToWalk = 1.5f;
	}
	if(randNum < 950)
	{
		isChangingDirection = true;
		idling = false;
		std::cout << "Changing Direction" << std::endl;
	}
	if(randNum > 950)
	{
		isChangingDirection = false;
		idling = true;
		totalCols = idleCols;
		std::cout << "Idling" << std::endl;
	}
	currentSpeed *= changeDirection();
	if(!idling)
		Human.setPosition(sf::Vector2f(Human.getPosition().x + currentSpeed * deltaTime, Human.getPosition().y));
}

//run once npc is dead
void BaseNPC::despawnTimer(float deltaTimer)
{
	despawner = despawner + deltaTimer;
	if(despawner > 3.0f)
		delete this;
}

//depending on gravity, the npc will either be constantly rising or falling
void BaseNPC::verticalMove(float deltaTime)
{
	if(!groundCollision())
		Human.setPosition(sf::Vector2f(Human.getPosition().x, Human.getPosition().y + (fallingSpeed * gravity * deltaTime)));
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
	DOT = DOT + deltaTime;
	if(DOT > 1.0f)
	{
		DOT = 0.0f;
		damageHP(2);
	}
}

void BaseNPC::setIsCold(float deltaTime)
{
	//play animation of npc freezing
	currentSpeed = changeSpeed()/2;
	//decrease their HP over time
	DOT = DOT + deltaTime;
	if(DOT > 1.0f)
	{
		DOT = 0.0f;
		damageHP(2);
	}
}

void BaseNPC::setIsHot(float deltaTime)
{
	//play animation of npc sweaty
	currentSpeed = changeSpeed()/2;
	//decrease their HP over time
	DOT = DOT + deltaTime;
	if(DOT > 1.0f)
	{
		DOT = 0.0f;
		damageHP(2);
	}
}

/*void BaseNPC::setIsWet(float deltaTime)
{
	//play animation of npc wet
}*/

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
		//isWet = true;
	}
	//hot and dry
	else if(weather.getTemperature() > 0 && weather.getMoisture() < 0)
	{
		isCold = false;
		isHot = true;
		//isWet = false;
	}
	//hot and pleasent
	else if(weather.getTemperature() > 0 && weather.getMoisture() == 0)
	{
		isCold = false;
		isHot = true;
		//isWet = false;
	}
	//cold and dry
	else if(weather.getTemperature() < 0 && weather.getMoisture() < 0)
	{
		isCold = true;
		isHot = false;
		//isWet = false;
	}
	//cold and wet
	else if(weather.getTemperature() < 0 && weather.getMoisture() > 0)
	{
		isCold = true;
		isHot = false;
		//isWet = false;
	}
	//cold and pleasent
	else if(weather.getTemperature() < 0 && weather.getMoisture() == 0)
	{
		isCold = true;
		isHot = false;
		//isWet = false;
	}
	//mild and pleasent
	else if(weather.getTemperature() == 0 && weather.getMoisture() == 0)
	{
		isCold = false;
		isHot = false;
		//isWet = false;
	}
	//mild and wet
	else if(weather.getTemperature() == 0 && weather.getMoisture() > 0)
	{
		isCold = false;
		isHot = false;
		//isWet = true;
	}
	//mild and dry
	else if(weather.getTemperature() == 0 && weather.getMoisture() < 0)
	{
		isCold = false;
		isHot = false;
		//isWet = false;
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
	return maxSpeed - gravity;
}

float BaseNPC::changeFallSpeed()
{
	return fallingSpeed = gravity;
}

//only call when npc is being spawned. should only be done once per spawn.
void BaseNPC::setPosition(sf::Vector2f v)
{
	Human.setPosition(v);
}
