#pragma once
#ifndef __state_machine__
#define __state_machine__


#include <stack>

#include "state_base.h"
#include "object.h"
#include "options.h"

namespace sf {
	class RenderWindow;
}

class _state_machine_
{
public:
	_state_machine_();

	// Create window and init subsystems
	bool Init();

	// Start game. Does not exit until the game is quit.
	bool Run();

protected:
	bool inited;
	sf::RenderWindow window;
	

	// State stack
	std::stack<StateBase*> states;

	Options options;
	Resources resources;
	
};


#endif
