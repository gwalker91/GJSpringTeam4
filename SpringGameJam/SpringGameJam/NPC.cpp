
#include "NPC.h"

NPC::NPC()
{}

//rand() % 200 + 100

NPC::NPC(sf::Vector2f pos)
	:health(MIN_HEALTH + (rand() % MAX_HEALTH)), walkSpeed(200),
	fallSpeed(200), direction(0), weatherState(8), DOT(0.5f), DOTDmg(0.1f),
	spriteTime(0.5f),
	idling(true), isHot(false), isCold(false), isAlive(true),
	isActive(true), 
	Human(sf::Sprite(*txtMap->at("NormalHuman"))),
	position(pos), col(0), row(0),
	idleCols(4), walkingCols(5), dyingCols(4)
{
	Human.setTextureRect(sf::IntRect(0, 0, 50, 100));
	totalCols = idleCols;
}

NPC::~NPC()
{

}

void NPC::updateWalkingSprite(float deltaTime)
{
	Human.setTextureRect(sf::IntRect(col * 50, row * 100, 50, 100));
	col++;
	if(col == totalCols)
	{
		col = 0;
	}
	std::cout << Human.getPosition().x << std::endl;
	Human.setPosition(position.x + (1000* deltaTime), position.y);
	std::cout << Human.getPosition().x << std::endl;
}

void NPC::changeDirection()
{

}

void NPC::kill()
{

}

void NPC::checkGround(float deltaTime)
{
	/*
	if(position.y <= SCREEN_HEIGHT * 0.75f)
	{
		Human.setPosition(position.x, position.y + (fallSpeed * gravity * deltaTime));
	}
	*/
}

void NPC::checkState()
{
	switch (weatherState)
	{
	case 0:
	case 1:
	case 2:
		isHot = true;
		isCold = false;
		Human = sf::Sprite(*txtMap->at("BurningHuman"));
		break;
	case 3:
	case 4:
	case 5:
		isCold = true;
		isHot = false;
		Human = sf::Sprite(*txtMap->at("FreezingHuman"));
		break;
	case 6:
	case 7:
	case 8:
		isCold = false;
		isHot = false;
		Human = sf::Sprite(*txtMap->at("NormalHuman"));
		break;
	}
}

void NPC::update(float deltaTime)
{
	DOT -= deltaTime;
	spriteTime -= deltaTime;
	if(DOT <= 0 && (isHot || isCold))
	{
		doDamage(DOTDmg);
		DOT = 0.5f;
	}
	if(spriteTime <= 0)
	{
		updateWalkingSprite(deltaTime);
		spriteTime = 0.5f;
	}

	checkGround(deltaTime);
}

void NPC::draw(sf::RenderWindow* w)
{
	w->draw(Human);
}

bool NPC::checkAlive()
{
	return isAlive;
}

void NPC::doDamage(int damage)
{
	health -= damage;
	if(health <= 0)
		isAlive = false;
}

void NPC::checkWeather(int weather)
{
	if(weatherState != weather)
	{
		weatherState = weather;
		checkState();
	}
}

