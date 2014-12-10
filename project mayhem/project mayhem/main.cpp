#include <cstdlib>
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "map.h"
#include "layer.h"
#include "object.h"
#include "log.h"
#include "state_machine.h"




int main()
{
	

	_state_machine_ e;
	
	if (e.Init())
		LOGI("Engine initialization completed successfully");
	else
	{
		LOGE("Failed to initialize engine");
		return EXIT_FAILURE;
	}
	

	if (e.Run())
		LOGI("Engine stopped");
	else
	{
		LOGE("Engine stopped with error");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


