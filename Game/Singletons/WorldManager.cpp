#include "WorldManager.h"

WorldManager* WorldManager::sInstance = nullptr;

WorldManager* WorldManager::GetInstance()
{
	if (!sInstance)
	{
		sInstance = new WorldManager();
	}

	return sInstance;
}

void WorldManager::TickActors(float deltaSeconds)
{
	std::list<std::shared_ptr<Actor>>::iterator it;

	for (it = mActors.begin(); it != mActors.end(); ++it)
	{
		it->get()->Tick(deltaSeconds);
	}
}

WorldManager::WorldManager()
{
}
