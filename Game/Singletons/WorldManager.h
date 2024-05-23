#pragma once
#include "Game/Private/GameCore/Utils.h"
#include "Game/Private/GameCore/ActorTypes.h"

#define WORLD WorldManager::GetInstance()


class WorldManager
{
public:

	static WorldManager* GetInstance();

	template<std::derived_from<Actor> ActorType, typename ...Args>
	std::shared_ptr<ActorType> SpawnActorOfClass(exVector2 spawnLocation, Args... arguments)
	{
		std::shared_ptr<ActorType> newActor = std::make_shared<ActorType>(arguments...);

		newActor->InitializeActor(spawnLocation);

		return newActor;
	}

private:

	WorldManager();

	static WorldManager* sInstance;
};

