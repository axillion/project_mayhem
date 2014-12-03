#ifndef __options__
#define __options__

// Most options are currently hardcoded, but having them in this class anyway
// makes them much easier to make configurable later on. It removes all the
// magic numbers from actual code which is a huge benefit.
class Options
{
	// The menu state is a friend of options and can thus access private members
	friend class StateMenu;

public:
	const int GetScreenWidth() const { return 1280; }
	const int GetScreenHeight() const { return 960; }
	const int GetBulletSpeed() const { return 700; }
	const int GetPlayerSpeed() const { return 300; }
	const int GetPlayerCount() const { return playerCount; }
protected:
	int playerCount;
};

#endif
