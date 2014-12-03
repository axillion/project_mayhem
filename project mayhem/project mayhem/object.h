#ifndef _object_
#define _object_

#include "resources.h"
#include <list>

namespace sf {

	class RenderWindow;
	class Sprite;

}

/*
namespace std {

	class objects;

}
*/

struct ObjectComparer;



// Small helper struct that contains tile size information

struct TileSize
{
	int x; // Width
	int y; // Height
	int s; // Spacing
};

class Object
{

	// Map needs to access protected/private data
	friend class Map;

public:

	Object(TileSize tileSize) : tileSize(tileSize) { }
	

	virtual void process(float deltaTime) {}
	virtual void draw(sf::RenderWindow& window) {}

	// Calculate x and y position of given tile in the texture
	void getTileCoords(int tile, int& x, int& y);

	const TileSize tileSize;

	// Edges returned by intersects hit detection algorithm
	enum Direction
	{
		UP = (1 << 0),
		DOWN = (1 << 1),
		LEFT = (1 << 2),
		RIGHT = (1 << 3)
	};

	//Object();
	Object(float x, float y, const sf::Texture& texture, TileSize tileSize);

	const float GetX() const { return x; }
	const float GetY() const { return y; }
	const float GetWidth() const { return width; }
	const float GetHeight() const { return height; }

	virtual void Process(float deltaTime, sf::RenderWindow& window) {}
	virtual void Draw(sf::RenderWindow& window);

	// Called when this object hit another object (never itself)
	virtual void Hit(Object& obj, unsigned int edges) {}

	// Returns true on object overlap.
	// Optional edges returned is from this object's view.
	virtual bool Intersects(const Object& obj, unsigned int* edges = nullptr) const;

	bool operator<(const Object& obj2) const { return priority < obj2.priority; }
	virtual ~Object();
	

protected:
	float x, y, width, height;
	sf::Sprite sprite;
	sf::Texture* texture;
	//std::list<Object*> objects;
	

	bool drawtobothwindows = false;
	int priority;
};

struct ObjectPointerComparer
{
	bool operator()(const Object* obj1, const Object* obj2) const
	{
		return *obj1 < *obj2;
	}
};

#endif