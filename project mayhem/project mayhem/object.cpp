#include <stdexcept>
#include <SFML/Graphics.hpp>

#include "log.h"
#include "object.h"
#include "resources.h"




Object::Object()
{
	x = y = 0;
	width = height = 0;
	priority = 0;
}

Object::Object(float x, float y, const sf::Texture& texture)
{
	this->x = x;
	this->y = y;

	sprite.setTexture(texture);

	width = (float)texture.getSize().x;
	height = (float)texture.getSize().y;
}

void Object::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(x, y);
	window.draw(sprite);
}

bool Object::Intersects(const Object& obj, unsigned int* layer) const
{
	unsigned char tmpEdges = 0;

	bool up =
		x + width > obj.x &&
		x < obj.x + obj.width &&
		y + height > obj.y &&
		y < obj.y;

	bool down =
		x + width > obj.x &&
		x < obj.x + obj.width &&
		y + height > obj.y + obj.height &&
		y < obj.y + obj.height;

	bool left =
		x + width > obj.x &&
		x < obj.x &&
		y + height > obj.y &&
		y < obj.y + obj.height;

	bool right =
		x + width > obj.x + obj.width &&
		x < obj.x + obj.width &&
		y + height > obj.y &&
		y < obj.y + obj.height;


	// Optionally output the edge information
	if (edges)
		*edges = tmpEdges;

	// True if any edge is set
	return (tmpEdges != 0);
}

TileObject::~TileObject()
{
	delete texture;
	texture = nullptr;
}

void TileObject::getTileCoords(int tile, int& x, int& y)
{
	// Tileid 0 means no tile, so the ids actually start from 1
	tile--;

	int tileXcount = texture->getSize().x / (tileSize.x + tileSize.s);

	x = (tile % tileXcount) * (tileSize.x + tileSize.s);
	y = (tile / tileXcount) * (tileSize.x + tileSize.s);


}
