#ifndef _state_base_
#define _state_base_
#include <vector>
#include <list>
#include "object.h"


namespace sf

{
class RenderWindow;
};

class Options;
class Resources;

// Base class for states, contains some default functionality
class StateBase
{
public:
	virtual ~StateBase();

	//View
	sf::View view;


	// Signals that states need to support

	// Called when processing should be done. Returns next state (e.g. this)
	virtual StateBase* Process(float deltaTime);

	// Called when drawing should be done
	virtual void Draw();
	bool tobeRemoved;
	//Class made to change cursor icon

	// Other possibly useful signals: Init(), Enter(), Exit(), Shutdown()
protected:
	// Protected constructor, prevents instantiation of base state
	StateBase(sf::RenderWindow& window, const Options& options, const Resources& resources, sf::View& view);
	
	// internal method running hit detection
	virtual void HitDetection();

	std::vector<Object*> objects;

	// External dependencies
	sf::RenderWindow& window;
	const Options& options;
	const Resources& resources;
	const sf::Font font;
};


#endif