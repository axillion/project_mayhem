#ifndef __bulletshot_h__
#define __bulletshot_h__

#include <SFML/Window.hpp>

#include "object.h"
#include "resources.h"
#include "options.h"
#include "state_machine.h"

class Bulletshot : public Object
{
public:

	Bulletshot(float x, float y, const sf::Texture& texture, float rotation, sf::Vector2f playerPos, sf::Vector2f mousePos);

	void Process(float deltaTime, sf::RenderWindow& window);

	void Draw(sf::RenderWindow& window);
	
	float speed = 200.0f;
	sf::Vector2f retning;
	sf::Vector2f playerPos;
	sf::Vector2f mousePos;

};

#endif

