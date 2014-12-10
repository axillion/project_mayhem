
#include <SFML/Window.hpp>

#include "options.h"
#include "log.h"
#include "state_machine.h"
#include "resources.h"
#include  "bulletshot.h"

Bulletshot::Bulletshot(float x, float y, const sf::Texture& texture, float rotation, sf::Vector2f playerPos, sf::Vector2f mousePos)
	: Object(x, y, texture)
{
	this->playerPos = playerPos;
	this->mousePos = mousePos;
	sprite.setRotation(rotation);
	priority = 1;
	speed = 800.0f;
	this->x = x;
	this->y = y;
	tobeRemoved = false;
}

void Bulletshot::Process(float deltaTime, sf::RenderWindow& window)
{
	sf::Vector2f retning = mousePos - playerPos;

	float length = sqrt((retning.x * retning.x) + (retning.y*retning.y));
//	if (length < 60.f) return;
	retning /= length;
	retning *= speed;

	x += retning.x * deltaTime;
	y += retning.y * deltaTime;

	
	if (x < 60 || x> 2480)
		{
			tobeRemoved = true;
	    }
		if (y < 60 || y>1920)
		{ 
			tobeRemoved = true;
		}
		
}

void Bulletshot::Draw(sf::RenderWindow& window)
{
	// Call the object version of Draw first
	Object::Draw(window);
}