#ifndef _state_playing_
#define _state_playing_

#include "state_base.h"



class StatePlaying : public StateBase
{
protected:
	// List of game objects. Should of course be put somewhere else in a bigger game
	std::list<Object*> objects;
public:
	StatePlaying(sf::RenderWindow& window, const Options& options, const Resources& resources);
	virtual StateBase* Process(float deltaTime);
	void HandleEvent(sf::Event& event);
};


#endif