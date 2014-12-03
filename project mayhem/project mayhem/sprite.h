#pragma once
#ifndef __sprite_h__
#define __sprite_h__

#include <SFML/System/Clock.hpp>

#include "object.h"


class Sprite : public Object
{
	//Map needs to access protected/private data
	friend class Map;

public:
	Sprite::Sprite(TileSize tileSize) : Object(tileSize) { }

	void process(float time);
	void draw(sf::RenderWindow& window);

protected:
	// Id of first tile
	int id;

	// Location on screen
	int x, y;

	// Current animation frame
	int frame;

	//Frame count (duh)
	int frameCount;

	// Length of one frame in ms
	int frameDuration;

	// Times the animation
	sf::Clock clock;

	~Sprite();
};
#endif

