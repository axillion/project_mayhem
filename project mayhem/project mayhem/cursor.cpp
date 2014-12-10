
#include <SFML/Window.hpp>

#include "options.h"
#include "log.h"
#include "state_machine.h"
#include "resources.h"
#include  "cursor.h"

Cursor::Cursor(const sf::Texture& texture)
{

	sprite.setTexture(texture);
	priority = 1;

}

void playercheck(sf::RenderWindow& window)
{


}

void Cursor::Draw(sf::RenderWindow& window)
{
		// Call the object version of Draw first
		Object::Draw(window);
}


void Cursor::Process(float deltaTime, sf::RenderWindow& window)
{
	//sf::Vector2f position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(mousePosition);
	this->x = worldPos.x;
	this->y = worldPos.y;
	
}