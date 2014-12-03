#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <list>
#include "layers.h"
#include "object.h"
#include "log.h"
#include "state_machine.h"
#include "map.h"


bool gameTick(sf::RenderWindow& window, std::list<Object*>& objects, float deltaTime)
{
	sf::Event event;

	// Process events from the OS
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			return true;

		case sf::Event::KeyReleased:
			// Reload map on F5
			if (event.key.code == sf::Keyboard::F5)
			{
				objects.clear();

				if (!Map::load("maps/mayhemlvl1.json", objects))
				{
					std::cout << "Failed to reload map data." << std::endl;
					return true;
				}
			}
			break;
		}
	}

	window.clear(sf::Color::Black);

	// Process and render each object
	for (Object* object : objects)
	{
		object->process(deltaTime);
		object->draw(window);
	}

	window.display();

	return false;
}

int main()
{

	// Standard SFML setup
	sf::RenderWindow window(sf::VideoMode(640, 480), "Project Mayhem");

	// Double the size of the screen
	sf::View view = window.getDefaultView();
	view.setSize(view.getSize().x / 2, view.getSize().y / 2);
	view.setCenter(view.getCenter().x / 2, view.getCenter().y / 2);
	window.setView(view);

	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);


	_state_machine_ e;
	
	if (e.Init())
		LOGI("Engine initialization completed successfully");
	else
	{
		LOGE("Failed to initialize engine");
		return EXIT_FAILURE;
	}
	

	if (e.Run())
		LOGI("Engine stopped");
	else
	{
		LOGE("Engine stopped with error");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

	
}


