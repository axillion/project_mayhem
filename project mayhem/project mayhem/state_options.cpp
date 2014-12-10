#include <sfml/Window.hpp>
#include <stdarg.h>
#include "log.h"
#include "object.h"
#include "state_options.h"
#include "state_menu.h"
#include "options.h"
#include "mainmenu.h"
#include "state_machine.h"



StateOptions::StateOptions(sf::RenderWindow& window, const Options& options, const Resources& resources)
	: StateBase(window, options, resources, view)
{

	/*
	sf::Texture texture;
	texture.loadFromFile("gfx/project_mayhem.png");
	sf::Sprite mainmenu;
	mainmenu.setTexture(texture, true);

	window.draw(mainmenu);
	window.display();
	*/

	optionsChoice = 0;
	MaxChoice = 4;

}
StateBase* StateOptions::Process(float deltaTime)
{

	// Used to make sure a key press is only used once
	static bool HasPressed = false;

	// Current state of menu keys
	bool EnterPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Return);
	bool UpPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	bool DownPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

	// Perform menu choice
	if (!HasPressed && EnterPressed)
	{
		switch (optionsChoice)
		{

		case 0:{
			break;

		}
		case 1:{
			LOGD("Changed blood settings");
			break;

			//const_cast<Options&>(options).playerCount = currentChoice + 1;
			//return new StatePlaying(window, options, resources, view);
		}
		case 2:{
			LOGD("Changed sound settings");
			break;
		}
		case 3:{
			LOGD("Reading about our awesome game...");
			break;
		}
		case 4:{
			LOGD("Quitting from options");
			//states.push(new StateMenu(window, options, resources, view));
			//return new StateMenu(window, options, resources, view);
			return nullptr;
			break;
		
			
		}
	  }
	}
	else if (!HasPressed && UpPressed && optionsChoice > 0){
		optionsChoice--;
		HasPressed=false;
	}
	else if (!HasPressed && DownPressed && optionsChoice < MaxChoice){
		optionsChoice++;
		HasPressed=false;
	}
	HasPressed = UpPressed || DownPressed || EnterPressed;
	return this;
}



void StateOptions::Draw()
{
	float startx = 500;
	float starty = 350;
	float stridey = 150;

	//Menuimage
	//Mainmenu* menu = new Mainmenu(0.0f, 0.0f, resources.GetTexture(Resources::Texture::MAINMENUIMAGE), options);




	// Texts could have been added in Enter() as game objects as well
	sf::Text optionMarker("------->", resources.GetFont());
	optionMarker.setPosition(startx - 95, starty + stridey * optionsChoice);

	sf::Text bloodChoice("Blood = On/Off", resources.GetFont());
	bloodChoice.setPosition(startx, starty);

	sf::Text soundChoice("Sound = On/Off", resources.GetFont());
	soundChoice.setPosition(startx, starty + stridey);

	sf::Text creditsChoice("Credits", resources.GetFont());
	creditsChoice.setPosition(startx, starty + stridey + stridey);

	sf::Text backChoice("Back", resources.GetFont());
	backChoice.setPosition(startx, starty + stridey * 3);


	window.draw(optionMarker);
	window.draw(bloodChoice);
	window.draw(creditsChoice);
	window.draw(soundChoice);
	window.draw(backChoice);

}
