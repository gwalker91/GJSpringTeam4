
#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

//KTZ was here..
//added a new extern int type
const extern int NUM_OF_PEOPLE;

extern int gravity;

typedef std::map<std::string, sf::Texture> TextureMap;
typedef std::pair<std::string, sf::Texture> MapPair;

extern TextureMap* txtMap;

#endif