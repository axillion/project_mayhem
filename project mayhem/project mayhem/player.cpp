#include <algorithm>
#include <sstream>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "options.h"
#include "player.h"
#include "resources.h"
#include "log.h"
#include "state_machine.h"
#include "math.h"



Player::Player(float x, float y, const sf::Texture& texture, 
	const Options& options)
	: Object(x, y, texture, tileSize), options(options)
{
	priority = 1;
	speed = 100;
	this->sprite.setOrigin(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2);
}

float Player::getRotation(sf::RenderWindow& window)
{
	sf::Vector2f curPos;
	curPos.x = sprite.getGlobalBounds().left;
	curPos.y = sprite.getGlobalBounds().top;
	sf::Vector2i position = sf::Mouse::getPosition(window);

	const float PI = 3.14159;

	float dx = position.x - curPos.x;
	float dy = position.y - curPos.y;

	float rotation = (atan2(dy, dx)) * 180 / PI;

	return rotation;
}

void Player::LookMouse(sf::RenderWindow& window)
{
	float rotation = getRotation(window);
	sprite.setRotation(rotation);
}

void Player::Draw(sf::RenderWindow& window)
{
	// Call the object version of Draw first
	Object::Draw(window);
}

void Player::Process(float deltaTime, sf::RenderWindow& window)
{
	getRotation(window);
	LookMouse(window);
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{

		sf::Vector2f direction = sf::Vector2f(sf::Mouse::getPosition(window)) - sprite.getPosition();

		float length = sqrt((direction.x * direction.x) + (direction.y*direction.y));
		if (length < 20.f) return;
		direction /= length;
		direction *= speed;

		this->x += direction.x * deltaTime;
		this->y += direction.y * deltaTime;
	}
}
