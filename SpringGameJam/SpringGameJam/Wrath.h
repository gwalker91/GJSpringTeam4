#ifndef WRATH_H
#define WRATH_H

#include "Globals.h"
#include <SFML/Graphics.hpp>

//Controls the wrath, tracks the wrath meter, 
class Wrath
{
public:	
	Wrath();
	~Wrath();

	bool checkWrathing();
	float getWrathDmg();
	void getWeather(int weather);

	//handle's user input
	void handleInput();

	//runs updates
	void update(float deltaTime);
	
	void draw(sf::RenderWindow* w);

private:
	//wrath counter
	float wrathPower;
	float spriteTimer;
	bool usingWrath;
	bool chargeWrath;

	sf::Sprite wrathImage;
	sf::Sprite wrathBar;
	int row, col;
	float wrathWidth;

	void updateSprite();

};

#endif