
#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

extern int gravity;

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




#endif