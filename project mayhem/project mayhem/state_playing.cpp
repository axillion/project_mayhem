#include <sfml/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "log.h"
#include "state_playing.h"
#include "state_pause.h"
#include "player.h"
#include "bottomlayer.h"
#include "map.h"



bool LoadMap(std::list<Object*>& objects)
{
	// Load map information from JSON into object list
	if (!Map::load("maps/mayhemlvl1.json", objects))
	{
		std::cout << "Failed to load map data." << std::endl;
		return false;
	}
	return true;

	
}



void StatePlaying::HandleEvent(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		// Reload map on F5
		if (event.key.code == sf::Keyboard::F5)
		{
			LoadMap(objects);
		}
		break;
	}
}


StatePlaying::StatePlaying(sf::RenderWindow& window, const Options& options, const Resources& resources)
	: StateBase(window, options, resources)
{
	Player* player = new Player(100.0, 100.0,resources.GetTexture(Resources::Texture::PLAYER1), options);
	objects.push_back(player);


//	Bottomlayer* bottomlayer = new Bottomlayer(0.0f, 0.0f, resources.GetTexture(Resources::Texture::BOTTOMLAYER), options);
//	objects.push_back(bottomlayer);

	
	

}


StateBase* StatePlaying::Process(float deltaTime)
{
	StateBase::Process(deltaTime);
	// Quit game when pressing escape
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		LOGD("Escape pressed, exiting game state");
		return nullptr;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		LOGD("Entering pause state from game state");
		//return new StatePause(window, options, resources);
	}
	return this;
}
