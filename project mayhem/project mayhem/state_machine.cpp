#include <SFML/Graphics.hpp>
#include "map.h"
#include "object.h"
#include "log.h"
#include "state_machine.h"
#include "state_menu.h"
#include "state_options.h"
#include "state_pause.h"
#include "state_playing.h"
#include "state_scores.h"
#include "state_post_level.h"
#include "state_scores.h"
#include "state_challenge_mode.h"


_state_machine_::_state_machine_()
{
	
	inited = false;
}

bool _state_machine_::Init()
{

	if (inited)
	{
		LOGW("Engine already initialized");
		return true;
	}

	// Pre-load all resources
	if (resources.Init())
		LOGI("Resource manager initialization completed successfully");
	else
	{
		LOGE("Failed to initialize resource manager");
		return false;
	}



	window.create(sf::VideoMode(options.GetScreenWidth(), options.GetScreenHeight()), "Project Mayhem");
	window.setMouseCursorVisible(false);

	// Double the size of the screen
	sf::View view = window.getDefaultView();
	view.setSize(view.getSize().x, view.getSize().y);
	view.setCenter(view.getCenter().x, view.getCenter().y);
	window.setView(view);
	
	
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);


	states.push(new StateMenu(window, options, resources, view));

	inited = true;

	return true;
}

bool _state_machine_::Run()
{
	if (!inited)
	{
		LOGE("Attempting to run engine before initialization");
		return false;
	}

	// Time everything to an actual timer, not framerate
	sf::Clock clock;
	float deltaTime = 0;

	// This is the actual game loop that runs until the game ends
	while (true)
	{
		sf::Event event;

		// Quit on window close
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				LOGD("Closed event received, shutting down engine");
				window.close();
				return true;
			}
			
			
		}

		StateBase* newState = states.top()->Process(deltaTime);

		// Draw the last state we processed before possibly changing state
		window.clear();
		states.top()->Draw();
		window.display();

		// Pop top state
		if (newState == nullptr)
		{
			// Remove current state
			delete states.top();
			states.pop();

			// Last state popped, exit
			if (states.size() == 0)
			{
				LOGD("Last state popped, shutting down engine");
				window.close();
				return true;
			}
		}
		// Push a new state
		else if (newState != states.top())
		{
			states.push(newState);
			// Don't advance time the first time the new state is run
			deltaTime = 0;
		}
		else
			deltaTime = clock.getElapsedTime().asSeconds();

		clock.restart();
	}
}
