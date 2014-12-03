#ifndef _state_scores_
#define _state_scores_

#include "state_base.h"

class Player;
class Scores;


class StateScores : public StateBase
{
public:
	StateScores(sf::RenderWindow& window, const Options& options, const Resources& resources);
	virtual StateBase* Process(float deltaTime);
};


#endif