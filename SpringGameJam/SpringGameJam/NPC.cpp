
#include "NPC.h"

NPC::NPC()
{}

NPC::NPC(sf::Vector2f pos)
	:health(MIN_HEALTH + (rand() % MAX_HEALTH)), walkSpeed(-50),
	fallSpeed(1250), direction(10.0f), weatherState(8), DOT(0.1f), DOTDmg(1.0f),
	spriteTime(0.2f), wrathed(false),
	idling(false), isHot(false), isCold(false), isAlive(true),
	isActive(true), falling(false),
	Human(sf::Sprite(*txtMap->at("NormalHuman"))),
	position(pos), col(0), row(2),
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
		walkSpeed = (walkSpeed/std::abs(walkSpeed)) * 100;
		break;
	case 3:
	case 4:
	case 5:
		isCold = true;
		isHot = false;
		Human = sf::Sprite(*txtMap->at("FreezingHuman"));
		walkSpeed = (walkSpeed/std::abs(walkSpeed)) * 20;
		break;
	case 6:
	case 7:
	case 8:
		isCold = false;
		isHot = false;
		Human = sf::Sprite(*txtMap->at("NormalHuman"));
		walkSpeed = (walkSpeed/std::abs(walkSpeed)) * 50;
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
		if(deltaTime < 1 && !idling)
			position.x += walkSpeed * deltaTime;
		if(position.x < 0 || position.x > SCREEN_WIDTH)
			changeDirection();
		Human.setPosition(position);
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
			
			spriteTime = 0.2f;
		}
		checkGround(deltaTime);
		checkGravity();
	}
	else
	{
		if(spriteTime <= 0)
		{
			updateDeath(deltaTime);
			spriteTime = 0.2f;
		}
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

void NPC::checkGravity()
{
	if(gravity > 1)
	{
		goingToDie = true;
		row = 5;
		totalCols = dyingCols;
		health = 0;
	}
}

