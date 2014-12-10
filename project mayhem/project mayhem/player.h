#ifndef __player_h__
#define __player_h__

#include <SFML/Window.hpp>

#include "object.h"
#include "resources.h"
#include "options.h"
#include "state_machine.h"
#include "bulletshot.h"
#include <list>


class Player : public Object
{
public:
	Player(float x, float y, const sf::Texture& texture, const Options& options, const Resources& resources, const sf::Font& font);
	void Process(float deltaTime, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);

	void Shot(sf::RenderWindow);

	sf::Vector2f getNextPosition() { return nextPosition; }
	
	void Move() {
		this->x = nextPosition.x;
		this->y = nextPosition.y;
	}

	void Reload() {
		this->bullets = +20;
	}

	float Player::getRotation(sf::RenderWindow& window);
	void Player::LookMouse(sf::RenderWindow& window);

	
	int getBulletCount(){ return bullets; }
	int getHealthCount(){ return hp; }

protected:
	int hp;;
	int bullets;
	float speed = 0;
	const Options& options;
	const Resources& resources;
	const sf::Font& font;
	float firerate = 0.5;
	float fireratecounter = 0;
	sf::Vector2f nextPosition = sf::Vector2f();
	


	


};

#endif
