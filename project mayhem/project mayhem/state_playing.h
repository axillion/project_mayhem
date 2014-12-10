#ifndef _state_playing_
#define _state_playing_

#include "state_base.h"
#include "object.h"
#include "player.h"



class StatePlaying : public StateBase
{
public:
	StatePlaying(sf::RenderWindow& window, const Options& options, const Resources& resources, sf::View& view);

	virtual StateBase* Process(float deltaTime);
	virtual void Draw();


	std::list<TileObject*> Objectlist;


	//virtual void Load(std::string filename, std::list<TileObject*>& objects);

private:
	Player* player;
	bool playerCanMove = true;

protected:
	
};


#endif