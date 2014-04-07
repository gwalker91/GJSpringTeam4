#include "Wrath.h"
#include "Globals.h"

Wrath::Wrath()
	:wrathImage(sf::Sprite((*txtMap->at("Wrath")))),
	wrathBar(sf::Sprite((*txtMap->at("WrathBar")))),
	wrathPower(0),
	usingWrath(false),
	chargeWrath(false),
	spriteTimer(0.5f),
	row(0), col(0),
	wrathWidth(1.0f)
{
	wrathBar.setPosition(10, 10);
}

Wrath::~Wrath()
{

}

void Wrath::updateSprite()
{
	col++;

	if (col == 3)
	{
		usingWrath = false;
		col = 0;
		wrathPower = 0;
	}
	wrathImage.setTextureRect(sf::IntRect(col * SCREEN_WIDTH, row * SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT));
}

bool Wrath::checkWrathing()
{
	return usingWrath;
}

float Wrath::getWrathDmg()
{
	return wrathPower;
}

void Wrath::getWeather(int weather)
{
	switch (weather)
	{
	case 1:
		row = 1;
		break;
	case 3:
	case 4:
	case 5:
		row = 2;
		break;
	case 0:
	case 2:
	case 6:
	case 7:
	case 8:
		row = 0;
		break;
	}
}

//***HANDLE INPUT***
void Wrath::handleInput()
{
	
	if(sf::Keyboard::isKeyPressed(chargeWrathButton))
	{
		if(!usingWrath)
		{
			wrathPower += 0.2f;
			chargeWrath = true;
		}
	}
	if(sf::Keyboard::isKeyPressed(unleashWrathButton) && wrathPower > 0)
	{
		usingWrath = true;
		wrathWidth = 1.0f;
		chargeWrath = false;
	}
	
}

//***UPDATE***
void Wrath::update(float deltaTime)
{
	if(usingWrath)
	{
		spriteTimer -= deltaTime;
		if(spriteTimer <= 0)
		{
			updateSprite();
			spriteTimer = 0.5f;
		}
	}
	if(chargeWrath)
	{
		if(wrathWidth <= 500)
			wrathWidth += 0.1f;
	}
	wrathBar.setTextureRect(sf::IntRect(0, 0, wrathWidth, 50));
	
}

void Wrath::draw(sf::RenderWindow* w)
{
	w->draw(wrathBar);
	if(usingWrath)
	{
		w->draw(wrathImage);
	}
	
}



