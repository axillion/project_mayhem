#ifndef _resources_
#define _resources_

#include <SFML/Graphics.hpp>

class Resources
{
public:
	// Texture identifier
	enum class Texture
	{
		PLAYER1,
		PLAYER2,
		CURSOR,
		MAINMENUIMAGE,
		BULLET,
		COUNT

	};

	Resources();

	// Preload all textures
	bool Init();

	// Get reference to pre-loaded texture
	const sf::Texture& GetTexture(Texture textureId) const;

	// Get reference to pre-loaded font
	const sf::Font& GetFont() const;

protected:
	sf::Texture textures[static_cast<size_t>(Texture::COUNT)];
	sf::Font font;
	bool inited;
};

#endif
