#ifndef __cursor_h__
#define __cursor_h__

#include <SFML/Window.hpp>

#include "object.h"
#include "resources.h"
#include "options.h"
#include "state_machine.h"

class Cursor : public Object
{
public:
	Cursor(const sf::Texture& texture);
	void Process(float deltaTime, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void playercheck(sf::RenderWindow& window);

protected:


};



#endif