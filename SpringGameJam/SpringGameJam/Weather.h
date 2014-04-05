#ifndef WEATHER_H
#define WEATHER_H

#include "Globals.h"

class Weather
{
public:
	//constructor
	Weather();
	//destructor
	~Weather();

	//runs updates
	void update(float deltaTime);

	//handles user input
	void handleInput();

	//getters
	int getMoisture();
	int getTemperature();
	int getTime();

	//setters
	void setMoisture(int newMoist);
	void setTemperature(int newTemp);
	void setTime(int newTime);

private:
	//basic weather variables
	// -1, 0, 1
	int moisture;
	int temperature;
	int time;
	//tracks current weather based off
	//of moisture and tempurature
	int weatherState;
};

#endif