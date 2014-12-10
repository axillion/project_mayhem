#ifndef _mainmenu_
#define _mainmenu_

#include <SFML/Window.hpp>

#include "resources.h"
#include "object.h"
#include "options.h"


class Mainmenu : public Object
{
public:
Mainmenu(float x, float y, const sf::Texture& texture, const Options& options);



private:
const Options& options;
sf::Image  Image;
sf::Sprite Sprite;



};
#endif