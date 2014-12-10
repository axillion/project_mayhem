#include "state_base.h"



StateBase::StateBase(sf::RenderWindow& window, const Options& options, const Resources& resources, sf::View& view)
	: window(window), options(options), resources(resources), view(view)
{ }

StateBase::~StateBase()
{
	// Free all game objects
	for (auto& p : objects)
		delete p;
}

StateBase* StateBase::Process(float deltaTime)
{
	std::list <Object*> templist;
	//std::list<TileObject*> templist2;

	// Do logic
	for (auto& obj : objects){
		obj->Process(deltaTime, window);

		//Copying the objects in Objectlist (bullets etc.) into templist, and then over to objects.
		for (auto& temp :obj ->Objectlist)
		{
			templist.push_back(temp);
		}
		obj->Objectlist.clear();

	}
	for (auto& temp : templist)
	{
		objects.push_back(temp);
	}
	
	for (auto it = objects.begin(); it != objects.end();)
	{
		if ((*it)->tobeRemoved == true){
			delete* it;
			it = objects.erase(it);
		}
		else
		{
			++it;
		}
	}
	
	return this;
}

void StateBase::Draw()
{
	// Sort all objects based on priority
	std::sort(objects.begin(), objects.end(), ObjectPointerComparer());

	// Draw objects
	for (auto obj : objects)
		obj->Draw(window);

}


void StateBase::HitDetection()
{
	// We simply test every object against every other object
	for (auto obj1 = objects.begin(); obj1 != objects.end(); obj1++)
	{
		for (auto obj2 = obj1; obj2 != objects.end(); obj2++)
		{
			// Skip self-collisions
			if (*obj1 == *obj2)
				continue;

			unsigned int edges;

			// We call the Intersects method twice because we want to get
			// the edges from both objects' point of view. This simplifies
			// collision handling in the objects quite a bit.

			if ((*obj1)->Intersects(**obj2, &edges))
				(*obj1)->Hit(**obj2, edges);

			if ((*obj2)->Intersects(**obj1, &edges))
				(*obj2)->Hit(**obj1, edges);
		}
	}
}

