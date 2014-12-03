#pragma once
#ifndef __layers_h__
#define __layers_h__

#include "object.h"


class Layer : public Object 
{

	// Map needs to access protected/private data
	friend class Map;

public:
	Layer(TileSize tileSize) : Object(tileSize) { }

	void draw(sf::RenderWindow& window);

protected:
	// Size in tiles
	int width, height;

	// Lazy, but ram is cheap!
	int tilemap[180][160];
	~Layer();
};
#endif

