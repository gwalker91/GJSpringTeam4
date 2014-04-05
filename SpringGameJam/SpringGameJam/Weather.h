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

		//getters
		float getGravity();
		int getMoisture();
		int getTempurature();
		int getTime();

		//setters
		void setGravity(float newGrav);
		void setMoisture(int newMoist);
		void setTempurature(int newTemp);
		void setTime(int newTime);

	private:
		//basic weather variables
		// -1, 0, 1
		int moisture;
		int temperature;
		float gravity;
		int time;
};

#endif