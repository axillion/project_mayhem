#include <sfml/Window.hpp>
#include "map.h"
#include "log.h"
#include "object.h"
#include "state_playing.h"
#include "state_menu.h"
#include "player.h"
#include "cursor.h"




//Draw tiles on window, loaded in by the json loader.
void StatePlaying::Draw()
{
	
	for (TileObject* object : Objectlist)
	{
		object->draw(window);
	}

	StateBase::Draw();
}


StatePlaying::StatePlaying(sf::RenderWindow& window, const Options& options, const Resources& resources, sf::View& view)
	: StateBase(window, options, resources, view)
{
	
	if (!Map::load("maps/mayhemMaplvl1.json", Objectlist))
	{
		std::cout << "Failed to load map data." << std::endl;

	}


	player = new Player(100.0, 100.0, resources.GetTexture(Resources::Texture::PLAYER1), options, resources, font);
	objects.push_back(player);



	/*bottomlayer* bottomlayer = new bottomlayer(0.0f, 0.0f, resources.gettexture(resources::texture::bottomlayer), options);
	objects.push_back(bottomlayer);
	*/

	Cursor* cursor = new Cursor(resources.GetTexture(Resources::Texture::CURSOR));
	objects.push_back(cursor);

	view.setCenter(player->GetPosition());
	view.move(player->GetPosition());
	window.setView(view);
}


StateBase* StatePlaying::Process(float deltaTime)
{
	StateBase::Process(deltaTime);

	// Quit game when pressing escape
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		LOGD("Escape pressed, exiting game state");
		return new StateMenu(window, options, resources,view);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		LOGD("Entering pause state from game state");
		//return new StatePause(window, options, resources);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))

	{
		//objects.clear();
		std::cout << "Engine refreshed game screen to show Mayhem lvl 1 Map" << std::endl;

		
	}

	for (TileObject* object : Objectlist)
	{
		object->process(deltaTime);
	}/*
		 if (object->contains(player->getNextPosition()))
			playerCanMove = false;
	}

	if (playerCanMove){
		player->Move();
	}
	playerCanMove = true;
	*/

		player->Move();



	view.setCenter(player->GetPosition());
	window.setView(view);

	
	return this;

}

