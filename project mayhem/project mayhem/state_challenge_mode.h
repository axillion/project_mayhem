#ifndef _state_challenge_mode_
#define _state_challenge_mode_

#include "state_base.h"



class StateChallengeMode : public StateBase
{
public:
	StateChallengeMode(sf::RenderWindow& window, const Options& options, const Resources& resources);
	virtual StateBase* Process(float deltaTime);
};


#endif