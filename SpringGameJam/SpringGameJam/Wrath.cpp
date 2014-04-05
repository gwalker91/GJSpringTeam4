#include "Wrath.h"
#include "Globals.h"

Wrath::Wrath()
{
	
}

Wrath::~Wrath()
{
	delete[] wrathCoor;
}

//***UPDATE***
void Wrath::update(float deltaTime)
{
	//update everything!
}

//***HANDLEINPUT***
void Wrath::handleInput()
{
	//handle's input
}

//*********getters************
int Wrath::getWrathCount()
{
	return wrathCount;
}

float* Wrath::getWrathCoor()
{
	return wrathCoor;
}

bool Wrath::getWrath()
{
	return wrath;
}

//**********Setters***********
void Wrath::setWrathCount(int newCount)
{
	wrathCount = newCount;
}

void Wrath::setWrathCoor(float newX, float newY)
{
	wrathCoor[0] = newX;
	wrathCoor[1] = newY;
}

void Wrath::setWrath(bool newWrath)
{
	wrath = newWrath;
}