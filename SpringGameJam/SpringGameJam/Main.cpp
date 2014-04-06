#include <SFML/Graphics.hpp>

//#include <vld.h>

#include "Engine.h"

void cleanUp(Engine* e);

int main()
{
    Engine* e = new Engine();
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

	while (e->getWindow()->isOpen())
    {
        sf::Event event;
        while (e->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
			{
				e->getWindow()->close();
			}
        }

		e->handleInput();
		e->update();
		e->draw();
    }

	cleanUp(e);

    return 0;
}

void cleanUp(Engine* e)
{
	delete e;
	txtMap->clear();
	delete txtMap;
}