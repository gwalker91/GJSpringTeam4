
#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

//KTZ was here..
//added a new extern int type to limit how many people can exist at once
const extern int NUM_OF_PEOPLE;

//KTZ was here...
//added another int to track how many people are still alive
extern int num_of_alive_people;

//KTZ was here...
//added another int to track how many people are active
extern int num_of_active_people;

extern float gravity;

typedef std::map<std::string, sf::Texture> TextureMap;
typedef std::pair<std::string, sf::Texture> MapPair;

extern TextureMap* txtMap;

//Takes care of the keys for the time of day
extern sf::Keyboard::Key dayButton;
extern sf::Keyboard::Key eveningButton;
extern sf::Keyboard::Key nightButton;

//Takes care of the keys for the temperature
extern sf::Keyboard::Key hotButton;
extern sf::Keyboard::Key mildButton;
extern sf::Keyboard::Key coldButton;

//Takes care of the keys for the moisture
extern sf::Keyboard::Key dryButton;
extern sf::Keyboard::Key pleasentButton;
extern sf::Keyboard::Key wetButton;

//Takes care of the keys for changing gravity
extern sf::Keyboard::Key upGravityButton;
extern sf::Keyboard::Key downGravityButton;

//Takes care of the keys for wrath
extern sf::Keyboard::Key chargeWrathButton;



#endif