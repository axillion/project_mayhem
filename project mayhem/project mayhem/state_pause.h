#ifndef _state_pause_
#define _state_pause_

#include "state_base.h"

class StatePause : public StateBase
{
public:
	StatePause(sf::RenderWindow& window, const Options& options, const Resources& resources, const sf::View view, const sf::Font& font);
	virtual StateBase* Process(float deltaTime);
	virtual void Draw();

protected:
	// We need to keep track of p so pause doesn't end right away
	bool wasPpressed;

	// True if we should quit the next time p isn't pressed
	bool shouldQuit;
};

#endif