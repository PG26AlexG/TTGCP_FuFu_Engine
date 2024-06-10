#pragma once
#include "Game/Private/GameCore/Utils.h"
#include "Game/Private/GameCore/ActorTypes.h"

#define WORLD WorldManager::GetInstance()


class WorldManager
{
public:
	static WorldManager* GetInstance();

	void TickActors (float deltaSeconds);

	template<std::derived_from<Actor> ActorType, typename ...Args>
	std::shared_ptr<ActorType> SpawnActorOfClass(exVector2 spawnLocation, Args... arguments)
	{
		std::shared_ptr<ActorType> newActor = std::make_shared<ActorType>(arguments...);

		newActor->InitializeActor(spawnLocation);

		mActors.push_back(newActor);
		return newActor;
	}

private:

	WorldManager();
	
	std::list<std::shared_ptr<Actor>> mActors;
	static WorldManager* sInstance;
};

