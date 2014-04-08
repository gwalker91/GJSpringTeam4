
#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

//KTZ was here..
//added a new extern int type to limit how many people can exist at once
const extern int NUM_OF_PEOPLE;
const extern int MAX_HEALTH;
const extern int MIN_HEALTH;

//KTZ was here...
//added another int to track how many people are still alive
extern int num_of_alive_people;

//KTZ was here...
//added another int to track how many people are active
extern int num_of_active_people;

extern float gravity;

typedef std::map<std::string, sf::Texture*> TextureMap;
typedef std::map<std::string, sf::SoundBuffer*> AudioMap;
typedef std::pair<std::string, sf::Texture*> MapPair;
typedef std::pair<std::string, sf::SoundBuffer*> MapPairAudio;

extern TextureMap* txtMap;
extern AudioMap* audMap;

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
extern sf::Keyboard::Key resetGravityButton;
extern sf::Keyboard::Key downGravityButton;

//Takes care of the keys for wrath
extern sf::Keyboard::Key chargeWrathButton;
extern sf::Keyboard::Key unleashWrathButton;

//SaveButton
extern sf::Keyboard::Key saveButton;




#endif