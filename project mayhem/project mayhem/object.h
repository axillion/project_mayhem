#ifndef _object_
#define _object_

#include "resources.h"
#include <list>

namespace sf {
	class RenderWindow;
	class Sprite;

}

// Small helper struct that contains tile size information
struct TileSize
{
	int x; // Width
	int y; // Height
	int s; // Spacing
};


struct ObjectComparer;

class Object
{
public:
	bool tobeRemoved = false;
	// Edges returned by intersects hit detection algorithm
	enum Direction
	{
		UP = (1 << 0),
		DOWN = (1 << 1),
		LEFT = (1 << 2),
		RIGHT = (1 << 3)
	};

	Object();
	Object(float x, float y, const sf::Texture& texture);

	const float GetX() const { return x; }
	const float GetY() const { return y; }
	const float GetWidth() const { return width; }
	const float GetHeight() const { return height; }

	virtual void Process(float deltaTime, sf::RenderWindow& window) {}
	virtual void Draw(sf::RenderWindow& window);

	// Called when this object hit another object (never itself)
	virtual void Hit(TileObject& objects, unsigned int layer) {}

	// Returns true on object overlap.

	// Optional edges returned is from this object's view.
	virtual bool Intersects(const Object& obj, unsigned int* layer = nullptr) const;

	bool operator<(const Object& obj2) const { return priority < obj2.priority; }
	std::list<Object*> Objectlist;


	const virtual sf::Vector2f GetPosition(){
		return sf::Vector2f(x, y);
	}

protected:
	float x, y, width, height;
	sf::Sprite sprite;
	int priority;

};

	
class TileObject
{
	// Map needs to access protected/private data
	friend class Map;

public:
	TileObject(TileObject::TileSize tileSize) : tileSize(tileSize) { }
	virtual ~TileObject();

	virtual void process(float deltaTime) {}
	virtual void draw(sf::RenderWindow& window) {}

	// Calculate x and y position of given tile in the texture
	void TileObject::getTileCoords(int tile, int& x, int& y);
	
	

	const TileSize tileSize;

protected:
	sf::Texture* texture;


};


struct ObjectPointerComparer
{
	bool operator()(const Object* obj1, const Object* obj2) const
	{
		return *obj1 < *obj2;
	}
};

#endif