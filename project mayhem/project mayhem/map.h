#ifndef __map_h__
#define __map_h__

#include <string>
#include <list>

#include "object.h"

namespace Json
{
	class Value;
}

// Class with a single public static function that loads a map into an object list
class Map
{
public:
	// Load map from Tiled JSON file
	static bool load(std::string filename, std::list<TileObject*>& objects);


private:
	// Handles regular layers
	static void loadLayer(Json::Value& layer, std::list<TileObject*>& objects, TileSize tileSize);

	// Handles object layers
	static void loadObjects(Json::Value& root, Json::Value& layer, std::list<TileObject*>& objects, TileSize tileSize);
};

#endif
