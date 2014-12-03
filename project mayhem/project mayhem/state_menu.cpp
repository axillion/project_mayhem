#include <sfml/Window.hpp>

#include "log.h"
#include "state_menu.h"
#include "state_playing.h"
#include "options.h"

StateMenu::StateMenu(sf::RenderWindow& window, const Options& options, const Resources& resources)
	: StateBase(window, options, resources)
{
	currentChoice = 0;
	maxChoice = 2;
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
		case 1:
			LOGD("Entering game state from main menu");

			// Cast away constness, as it is needed (but only here)
			const_cast<Options&>(options).playerCount = currentChoice + 1;

			return new StatePlaying(window, options, resources);
		case 2:
			LOGD("Quitting from main menu");
			return nullptr;
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
	float startx = 300;
	float starty = 150;
	float stridey = 40;

	// Texts could have been added in Enter() as game objects as well

	sf::Text marker("*", resources.GetFont());
	marker.setPosition(startx - 30, starty + stridey * currentChoice);

	sf::Text singlePlayerChoice("Single player", resources.GetFont());
	singlePlayerChoice.setPosition(startx, starty);

	sf::Text multiPlayerChoice("Multi player", resources.GetFont());
	multiPlayerChoice.setPosition(startx, starty + stridey);

	sf::Text exitChoice("Exit", resources.GetFont());
	exitChoice.setPosition(startx, starty + stridey * 2);

	window.draw(marker);
	window.draw(singlePlayerChoice);
	window.draw(multiPlayerChoice);
	window.draw(exitChoice);
}
