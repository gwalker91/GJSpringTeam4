
#ifndef NPC_H
#define NPC_H

#include "Entity.h"
#include "Globals.h"
#include "Weather.h"
#include <random>

class NPC
{
private:

	int walkSpeed;
	int fallSpeed;
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
	float direction;

	bool idling;
	bool isHot;
	bool isCold;
	bool isAlive;
	bool isActive;
	bool falling;
	bool wrathed;
	bool goingToDie;

	sf::Sprite Human;
	sf::Vector2f position;
	sf::SoundBuffer iceDeath;
	sf::SoundBuffer electricDeath;
	sf::SoundBuffer flameDeath;

	void updateWalkingSprite(float deltaTime);
	void updateDeath(float deltaTime);
	void changeDirection();
	void kill();
	void killWithWrath();
	void checkGround(float deltaTime);
	void checkState();
public: 
		float health;
	NPC();
	NPC(sf::Vector2f pos);
	~NPC();
	void update(float deltaTime);
	void draw(sf::RenderWindow* w);

	bool checkAlive();
	void doDamage(float damage, bool isWrath);

	void checkWeather(int weather);
};

#endif