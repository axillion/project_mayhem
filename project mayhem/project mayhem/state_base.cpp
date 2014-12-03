#include "state_base.h"

StateBase::StateBase(sf::RenderWindow& window, const Options& options, const Resources& resources)
	: window(window), options(options), resources(resources)
{ }

StateBase::~StateBase()
{
	// Free all game objects
	for (auto& p : objects)
		delete p;
}

StateBase* StateBase::Process(float deltaTime)
{
	// Do logic
	for (auto& obj : objects)
		obj->Process(deltaTime, window);

	// Perform hit detection
	HitDetection();

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

void StateBase::HandleEvent(sf::Event& event)
{

}
