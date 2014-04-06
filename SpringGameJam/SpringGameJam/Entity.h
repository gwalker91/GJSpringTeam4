
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

//Everything will extend off of this class
//That way we can put them all into a vector in engine and update 
//them all
class Entity
{
private:

public:
	//Entity();
	//~Entity();
	void update(float deltaTime);
	void draw(sf::RenderWindow* w);
};

#endif