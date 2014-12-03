#ifndef __player_h__
#define __player_h__

#include <SFML/Window.hpp>

#include "object.h"
#include "resources.h"
#include "options.h"
#include "state_machine.h"

class Player : public Object
{
public:
	Player(float x, float y,const sf::Texture& texture,const Options& options);
	void Process(float deltaTime, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);

	float Player::getRotation(sf::RenderWindow& window);
	void Player::LookMouse(sf::RenderWindow& window);

protected:

	float speed = 0;
	// void Move(Direction direction, float deltaTime);

	void attack(sf::RenderWindow& window);
	void mover(sf::RenderWindow& window);

	const Options& options;

	


};

#endif
