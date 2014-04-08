
#include "Globals.h"

int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 600;

//KTZ was here..
//added a new int to limit how many people can exist at once
const int NUM_OF_PEOPLE = 5;
const int MAX_HEALTH = 15;
const int MIN_HEALTH = 5;

//KTZ was here...
//added another int to track how many people are still alive
int num_of_alive_people = 0;

//KTZ was here...
//added another int to track how many people are active
int num_of_active_people = 0;

float gravity = 1.0f;

TextureMap* txtMap = new TextureMap();
AudioMap* audMap = new AudioMap();

//This can be hold for the verve
sf::Keyboard::Key dayButton = sf::Keyboard::Q;
sf::Keyboard::Key eveningButton = sf::Keyboard::W;
sf::Keyboard::Key nightButton = sf::Keyboard::E;

//This can be hold for verve
sf::Keyboard::Key hotButton = sf::Keyboard::A;
sf::Keyboard::Key mildButton = sf::Keyboard::S;
sf::Keyboard::Key coldButton = sf::Keyboard::D;

//This can be hold for verve
sf::Keyboard::Key dryButton = sf::Keyboard::Z;
sf::Keyboard::Key pleasentButton = sf::Keyboard::X;
sf::Keyboard::Key wetButton = sf::Keyboard::C;

//This should be sent 1 a second for verve
sf::Keyboard::Key upGravityButton = sf::Keyboard::I;
sf::Keyboard::Key resetGravityButton = sf::Keyboard::O;
sf::Keyboard::Key downGravityButton = sf::Keyboard::P;

//This should be sent 2 per second for verve
sf::Keyboard::Key chargeWrathButton = sf::Keyboard::L;
sf::Keyboard::Key unleashWrathButton = sf::Keyboard::K;

//This should be one time press for verve
sf::Keyboard::Key saveButton = sf::Keyboard::M;

