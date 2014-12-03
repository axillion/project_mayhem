#ifndef _state_menu_
#define _state_menu_

#include "state_base.h"

class StateMenu : public StateBase
{
public:
	StateMenu(sf::RenderWindow& window, const Options& options, const Resources& resources);
	virtual StateBase* Process(float deltaTime);
	virtual void Draw();

protected:
	int currentChoice;
	int maxChoice;
};

#endif