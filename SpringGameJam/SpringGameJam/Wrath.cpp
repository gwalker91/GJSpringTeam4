#include "Wrath.h"

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

//*********getters************
int Wrath::getWrathCount()
{
	return wrathCount;
}

int* Wrath::getWrathCoor()
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

void Wrath::setWrathCount(float newX, float newY)
{
	wrathCoor[0] = newX;
	wrathCoor[1] = newY;
}

void Wrath::setWrathCount(int newWrath)
{
	wrath = newWrath;
}