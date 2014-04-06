
#include "Globals.h"

int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 600;

//KTZ was here..
//added a new extern int type
const int NUM_OF_PEOPLE = 5;

float gravity = 2;

TextureMap* txtMap = new TextureMap();

sf::Keyboard::Key dayButton = sf::Keyboard::Q;
sf::Keyboard::Key eveningButton = sf::Keyboard::W;
sf::Keyboard::Key nightButton = sf::Keyboard::E;

//Takes care of the keys for the temperature
sf::Keyboard::Key hotButton = sf::Keyboard::A;
sf::Keyboard::Key mildButton = sf::Keyboard::S;
sf::Keyboard::Key coldButton = sf::Keyboard::D;

//Takes care of the keys for the moisture
sf::Keyboard::Key dryButton = sf::Keyboard::Z;
sf::Keyboard::Key pleasentButton = sf::Keyboard::X;
sf::Keyboard::Key wetButton = sf::Keyboard::C;

//Takes care of the keys for changing gravity
sf::Keyboard::Key upGravityButton = sf::Keyboard::O;
sf::Keyboard::Key downGravityButton = sf::Keyboard::P;
