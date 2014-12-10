#include <SFML/Graphics.hpp>

#include "options.h"
#include "mainmenu.h"
#include "resources.h"


Mainmenu::Mainmenu(float x, float y, const sf::Texture& texture, const Options& options) : Object(x, y, texture), options(options)
{
priority = 0;
}



