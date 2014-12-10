#ifndef __options__
#define __options__

// Most options are currently hardcoded, but having them in this class anyway
// makes them much easier to make configurable later on. It removes all the
// magic numbers from actual code which is a huge benefit.
class Options
{
	// The menu state is a friend of options and can thus access private members
	friend class StateMenu;
	int ScreenWidth = 1280;
	int ScreenHeight = 960;
public:
	const int GetScreenWidth() const { return ScreenWidth; }
	const int GetScreenHeight() const { return ScreenHeight; }
	const int GetBulletSpeed() const { return 700; }
	const int GetPlayerSpeed() const { return 300; }
	const int GetPlayerCount() const { return playerCount; }
	const int GetPlayerHealth() const { return playerHealth;  }
	const int GetPlayerArmor() const { return playerArmor;  }
	const int GetOptionChoice() const { return optionChoice; }

	bool playerShield;
	int optionChoice;

protected:
	int playerCount;
	int playerHealth;
	int playerArmor;
	
};

#endif
