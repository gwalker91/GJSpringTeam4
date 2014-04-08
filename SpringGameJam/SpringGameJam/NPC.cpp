
#include "NPC.h"

NPC::NPC()
{}

NPC::NPC(sf::Vector2f pos)
	:health(MIN_HEALTH + (rand() % MAX_HEALTH)), walkSpeed(3000),
	fallSpeed(1250), direction(10.0f), weatherState(8), DOT(0.1f), DOTDmg(1.0f),
	spriteTime(0.2f), wrathed(false),
	idling(false), isHot(false), isCold(false), isAlive(true),
	isActive(true), falling(false),
	Human(sf::Sprite(*txtMap->at("NormalHuman"))),
	position(pos), col(0), row(0),
	idleCols(4), walkingCols(5), dyingCols(4)
{
	Human.setPosition(position);
	Human.setTextureRect(sf::IntRect(0, 0, 50, 100));
	totalCols = idleCols;
	goingToDie = false;
}

NPC::~NPC()
{

}

void NPC::updateWalkingSprite(float deltaTime)
{
	if(!falling)
	{
		Human.setTextureRect(sf::IntRect(col * 50, row * 100, 50, 100));
		col++;
		if(col == totalCols)
		{
			if(row != 4)
				col = 0;
		}
		if(deltaTime < 1 && !idling)
			position.x += walkSpeed * deltaTime;
		Human.setPosition(position);
	}
}

void NPC::updateDeath(float deltaTime)
{
	if(col < totalCols)
	{
		Human.setTextureRect(sf::IntRect(col * 50, row * 100, 50, 100));
		col++;
	}
	if(col == totalCols)
	{
		if(row != 4)
			col = 0;
		if(health <= 0)
			isAlive = false;
		wrathed = false;
	}
}

void NPC::changeDirection()
{
	walkSpeed *= -1;
	direction = rand() % 10;
	col = 0;
	if(rand() % 100 < 60)
	{
		idling = false;
	}
	else
		idling = true;
	if(!idling)
	{
		if(walkSpeed < 0)
			row = 2;
		else
			row = 3;
	}
	else
	{
		if(walkSpeed < 0)
			row = 0;
		else
			row = 1;
	}

}

void NPC::kill()
{
	goingToDie = true;
	row = 4;
	col = 0;
	totalCols = dyingCols;
}

void NPC::killWithWrath()
{
	row = 4;
	col = 0;
	totalCols = dyingCols;
	wrathed = true;

}

void NPC::checkGround(float deltaTime)
{
	if(position.y <= SCREEN_HEIGHT * 0.75f || gravity < 0)
	{
		if(deltaTime < 1)
		{
			position.y += fallSpeed * gravity * deltaTime;
			Human.setPosition(position);
		}
		falling = true;
	}
	else
		falling = false;

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
	Human.setTextureRect(sf::IntRect(0, 0, 50, 100));
	Human.setPosition(position.x, position.y);
}

void NPC::update(float deltaTime)
{
	spriteTime -= deltaTime;
	if(!goingToDie && !wrathed)
	{
		direction -= deltaTime;
		if((isHot || isCold))
			DOT -= deltaTime;
		if(direction <= 0)
		{
			changeDirection();
		}
		if(DOT <= 0)
		{
			doDamage(DOTDmg, false);
			DOT = 0.5f;
		}
		if(spriteTime <= 0)
		{
			updateWalkingSprite(deltaTime);
			checkGround(deltaTime);
			spriteTime = 0.2f;
		}
	}
	else
	{
		if(spriteTime <= 0)
		{
			updateDeath(deltaTime);
			spriteTime = 0.2f;
		}
	}

	if(position.y <= 0)
	{
		isAlive = false;
	}
}

void NPC::draw(sf::RenderWindow* w)
{
	w->draw(Human);
}

bool NPC::checkAlive()
{
	return isAlive;
}

void NPC::doDamage(float damage, bool isWrath)
{
	if(!isWrath)
		health -= damage;
	if(isWrath)
	{
		if(!wrathed)
			health -= damage;
		killWithWrath();
	}
	else if(health <= 0 && !isWrath)
		kill();
}

void NPC::checkWeather(int weather)
{
	if(weatherState != weather)
	{
		weatherState = weather;
		checkState();
	}
}

