#include <stdexcept>

#include <SFML/Graphics.hpp>

#include "log.h"
#include "resources.h"

// Internal structure mapping texture id to path
struct TextureMapping
{
	Resources::Texture texture;
	const char* const path;
};

Resources::Resources() { inited = false; }

bool Resources::Init()
{
	static struct TextureMapping textureList[] =
	{
		{ Texture::PLAYER1, "gfx/player1.png" },
		{ Texture::PLAYER2, "gfx/player1.png" },
		//{Texture::BOTTOMLAYER,"gfx/mayhemlvl1.png"}

	};

	if (inited)
	{
		LOGW("Texture manager has already been initialized");
		return true;
	}

	LOGI("Loading textures...");

	for (size_t i = 0; i < (int)Texture::COUNT; i++)
	{
		if (textures[(size_t)textureList[i].texture].loadFromFile(textureList[i].path))
			LOGD("Texture loaded: " << textureList[i].path);
		else
		{
			LOGE("Failed to load texture: " << textureList[i].path);
			return false;
		}
	}

	LOGI("Loading font...");

	font.loadFromFile("sansation.ttf");

	inited = true;

	return true;
}

const sf::Texture& Resources::GetTexture(Resources::Texture textureId) const
{
	LOGD("Getting texture: " << (size_t)textureId);

	if (textures[(size_t)textureId].getSize().x == 0)
		throw std::runtime_error("Attempting to fetch empty texture");

	return textures[(size_t)textureId];
}

const sf::Font& Resources::GetFont() const
{
	return font;
}
