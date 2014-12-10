#ifndef __layer_h__
#define __layer_h__

#include "object.h"

// Class representing a tile layer
class Layer : public Object, public TileObject
{
	// Map needs to access protected/private data
	friend class Map;

public:
	Layer::Layer(TileSize tileSize) : TileObject(tileSize) { }

	void draw(sf::RenderWindow& window);

	

protected:
	int priority;
	// Size in tiles
	int width, height;

	// Lazy, but ram is cheap!
	int tilemap[800][600];
};

#endif
