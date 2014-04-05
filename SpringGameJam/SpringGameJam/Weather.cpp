#include "Weather.h"

Weather::Weather()
{

}

Weather::~Weather()
{

}

void Weather::update(float deltaTime)
{
	//do them updates
}

//****getters****
float Weather::getGravity()
{
	return gravity;
}

int Weather::getMoisture()
{
	return moisture;
}

int Weather::getTempurature()
{
	return tempurature;
}

int Weather::getTime()
{
	return time
}

//****setters****
void Weather::setGravity(float newGrav)
{
	gravity = newGrav
}

void Weather::setMoisture(int newMoist)
{
	moisture = newMoist;
}

void Weather::setTempurature(int newTemp)
{
	tempurature = newTemp;
}

void Weather::setTime(int newTime)
{
	time = newTime
}

