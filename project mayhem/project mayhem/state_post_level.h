#ifndef state_post_level_
#define state_post_level_

#include "state_base.h"

class Loader;

class StatePostLevel : public StateBase
{
public:
	StatePostLevel(sf::RenderWindow& window, const Options& options, const Resources& resources, const sf::View view);
	virtual StateBase* Process(float deltaTime);


};

#endif