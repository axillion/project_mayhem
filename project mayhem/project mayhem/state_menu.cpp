#include <sfml/Window.hpp>
#include <stdarg.h>
#include "log.h"
#include "object.h"
#include "state_menu.h"
#include "state_playing.h"
#include "state_options.h"
#include "options.h"
#include "mainmenu.h"



void StateMenu::DrawPic(){

	sf::Texture texture;
	texture.loadFromFile("gfx/project_mayhem.png");
	sf::Sprite mainmenu;
	mainmenu.setTexture(texture, true);

	window.draw(mainmenu);
	window.display();

}

StateMenu::StateMenu(sf::RenderWindow& window, const Options& options, const Resources& resources, sf::View& view)
	: StateBase(window, options, resources, view)
{

	currentChoice = 0;
	maxChoice = 3; 
}

StateBase* StateMenu::Process(float deltaTime)
{

	// Used to make sure a key press is only used once
	static bool hasPressed = false;

	// Current state of menu keys
	bool enterPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Return);
	bool upPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	bool downPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

	// Perform menu choice
	if (!hasPressed && enterPressed)
	{
		switch (currentChoice)
		{
			// Common code for 1 and 2 players
		case 0:
			LOGD("Entering game state from main menu");

			// Cast away constness, as it is needed (but only here)
			const_cast<Options&>(options).playerCount = currentChoice + 1;
			return new StatePlaying(window, options, resources, view);
			break;
		case 1:
			LOGD("Multiplayer with ManyMouse library is coming soon.");
			break;

			
		case 2:
			return new StateOptions(window, options, resources);
			break;

		case 3:
			LOGD("Quitting from main menu");
			return nullptr;
			break;
		}
	}
	else if (!hasPressed && upPressed && currentChoice > 0)
		currentChoice--;
	else if (!hasPressed && downPressed && currentChoice < maxChoice)
		currentChoice++;
	hasPressed = upPressed || downPressed || enterPressed;
	return this;
}



void StateMenu::Draw()
{
	float startx = 500;
	float starty = 350;
	float stridey = 150;

	//Menuimage
	//Mainmenu* menu = new Mainmenu(0.0f, 0.0f, resources.GetTexture(Resources::Texture::MAINMENUIMAGE), options);
	
	
	

	// Texts could have been added in Enter() as game objects as well
	sf::Text marker("------->", resources.GetFont());
	marker.setPosition(startx - 95, starty + stridey * currentChoice);

	sf::Text singlePlayerChoice("Single player", resources.GetFont());
	singlePlayerChoice.setPosition(startx, starty);

	sf::Text multiPlayerChoice("Multiplayer - ManyMouse version coming soon", resources.GetFont());
	multiPlayerChoice.setPosition(startx, starty + stridey);

	sf::Text optionsChoice("Options", resources.GetFont());
    optionsChoice.setPosition(startx, starty + stridey + stridey);

	sf::Text exitChoice("Exit", resources.GetFont());
	exitChoice.setPosition(startx, starty + stridey * 3);

	
	window.draw(marker);
	window.draw(singlePlayerChoice);
	window.draw(optionsChoice);
	window.draw(multiPlayerChoice);
	window.draw(exitChoice);

}
