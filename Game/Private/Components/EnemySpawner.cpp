#include "EnemySpawner.h"

#include "Game/Private/Game.h"

#include "RunnerComponent.h"
#include "Game/Private/GameCore/ActorTypes.h"
#include "Game/Private/GameCore/ComponentTypes.h"
#include "Game/Singletons/WorldManager.h"

TimerComponent* TimerComponent::mInstance;


EnemySpawner::EnemySpawner(std::shared_ptr<Actor> owner) : Component(owner)
{

}

void EnemySpawner::InitializeComponent()
{
}

void EnemySpawner::TickComponent(float deltaSeconds)
{
	if ((int)TIMER->elapsedTime % 3 == 0)
	{
		if (!canSpawn) return;
		std::shared_ptr<Box> obstacle = WORLD->SpawnActorOfClass<Box>(exVector2{ 1000.0f, 500.0f }, exColor{ 0, 255, 0, 255 }, 50.0f, 75.0f);
		obstacle->AddComponentOfType<ObsticleCompoent>();
		ObstacleList.push_back(obstacle);

		canSpawn = false;
	}
	else 
	{

		canSpawn = true;
	}
}
