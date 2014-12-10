#ifndef _state_options_
#define _state_options_

#include "state_base.h"


class StateOptions : public StateBase
{
public:
	StateOptions(sf::RenderWindow& window, const Options& options, const Resources& resources);
	virtual StateBase* Process(float deltaTime);
	virtual void Draw();

protected:
	int optionsChoice;
	int MaxChoice;

};


#endif