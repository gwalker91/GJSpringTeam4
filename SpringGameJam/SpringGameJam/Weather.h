#ifndef WEATHER_H
#define WEATHER_H

#include "Globals.h"
#include "ParticleSystem.h" 

#include <SFML/Graphics.hpp>

#include <iostream>

class Weather
{
public:
	//constructor
	Weather();
	//destructor
	~Weather();
	
	//handles user input
	void handleInput();

	//runs updates
	void update(float deltaTime);

	void draw(sf::RenderWindow* w);

	//getters
	int getMoisture();
	int getTemperature();
	int getTime();
	int getWeather();

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

	int heavyRain, lightRain, noRain;

	ParticleSystem rainSystem;
	sf::Sprite* clouds;
	sf::Sprite* darkness;
};

#endif