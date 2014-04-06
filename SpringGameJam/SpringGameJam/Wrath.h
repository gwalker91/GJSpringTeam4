#ifndef WRATH_H
#define WRATH_H

#include "Globals.h"

//Controls the wrath, tracks the wrath meter, 
class Wrath
{
public:	
	Wrath();
	~Wrath();

	//runs updates
	void update(float deltaTime);

	//handle's user input
	void handleInput();

	//getters
	int getWrathCount();
	float* getWrathCoor();
	bool getWrath();

	//setters
	void setWrathCount(int newCount);
	void setWrathCoor(float newX, float newY);
	void setWrath(bool newWrath);

private:
	//wrath counter
	int wrathCount;
	//Smite? y/n:
	bool wrath;
	//wrath location (x,y)
	float wrathCoor[2];

	sf::Sprite wrathImage;
};

#endif