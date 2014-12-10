#include <algorithm>
#include <sstream>
#include <cmath>'
#include "math.h"'
#include <SFML/Graphics.hpp>
#include "options.h"
#include "player.h"
#include "resources.h"
#include "log.h"
#include "state_machine.h"
#include "bulletshot.h"
#include "state_playing.h"

Player::Player(float x, float y, const sf::Texture& texture, const Options& options, const Resources& resources, const sf::Font& font)
	: Object(x, y, texture), options(options), resources(resources), font(font)
{

	hp = 100;
	bullets = 20;
	priority = 1;
	speed = 150;
	this->sprite.setOrigin(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2);
		
	this->x = x;
	this->y = y; 
	nextPosition.x = x;
	nextPosition.y = y;

	std::list<Bulletshot*> bulletshotz;
}


float Player::getRotation(sf::RenderWindow& window)
{
	sf::Vector2f curPos;
	curPos.x = sprite.getGlobalBounds().left;
	curPos.y = sprite.getGlobalBounds().top;
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f position = window.mapPixelToCoords(mousePos);

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

	sf::Text hpbar(std::to_string(hp), resources.GetFont());
	hpbar.setPosition(nextPosition.x-10, nextPosition.y-40);

	sf::Text ammobar(std::to_string(bullets), resources.GetFont());
	ammobar.setPosition(nextPosition.x-10, nextPosition.y+25);


	window.draw(hpbar);
	window.draw(ammobar);

	
}

void Player::Process(float deltaTime, sf::RenderWindow& window)
{
	getRotation(window);
	LookMouse(window);

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		Player::Reload();
		LOGD("Reloaded a new ammo clip");

	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f direction = window.mapPixelToCoords(mousePos) - sprite.getPosition();

		float length = sqrt((direction.x * direction.x) + (direction.y*direction.y));
		if (length < 60.f) return;
		direction /= length;
		direction *= speed;

		nextPosition.x += direction.x*deltaTime;
		nextPosition.y += direction.y*deltaTime;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
	{

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f direction = window.mapPixelToCoords(mousePos) - sprite.getPosition();

		float length = sqrt((direction.x * direction.x) + (direction.y*direction.y));
		if (length < 60.f) return;
		direction /= length;
		direction *= speed;

		nextPosition.x -= direction.x * deltaTime;
		nextPosition.y -= direction.y * deltaTime;
	}

	 if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{	
		 if (bullets != 0){
			 if (fireratecounter >= firerate){

				 sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				 sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
				 sf::Vector2f direction = worldPos - sprite.getPosition();
				 sf::Vector2f playerPos = sprite.getPosition();
				 Bulletshot* bullet = new Bulletshot(x, y, resources.GetTexture(Resources::Texture::BULLET), getRotation(window), playerPos, worldPos);
				 Objectlist.push_back(bullet);
				 bullets--;
				 fireratecounter = 0;
			 }

		 }
	}

	 fireratecounter += deltaTime;
}
