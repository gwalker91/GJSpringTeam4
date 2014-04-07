
#ifndef NPC_H
#define NPC_H

#include "Entity.h"
#include "Globals.h"
#include "Weather.h"
#include <random>

class NPC
{
private:
	float health;
	int walkSpeed;
	int fallSpeed;
	int direction;
	int weatherState;

	int row;
	int col;
	int totalCols;

	int idleCols;
	int walkingCols;
	int dyingCols;

	float DOT;
	float DOTDmg;
	float spriteTime;

	bool idling;
	bool isHot;
	bool isCold;
	bool isAlive;
	bool isActive;

	sf::Sprite Human;
	sf::Vector2f position;

	void updateWalkingSprite(float deltaTime);
	void changeDirection();
	void kill();
	void checkGround(float deltaTime);
	void checkState();
public: 
	NPC();
	NPC(sf::Vector2f pos);
	~NPC();
	void update(float deltaTime);
	void draw(sf::RenderWindow* w);

	bool checkAlive();
	void doDamage(int damage);
	void checkWeather(int weather);
};

#endif