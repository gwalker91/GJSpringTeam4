
#include "Globals.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

int gravity = 2;

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