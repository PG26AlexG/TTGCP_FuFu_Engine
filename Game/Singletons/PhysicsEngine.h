#pragma once
#include "Game/Private/GameCore/Utils.h"

#define PHYSICS_ENGINE PhysicsEngine::GetInstance()

class PhysicsComponent;

class PhysicsEngine
{
public:

	static PhysicsEngine* GetInstance();

	// will add physics components to physics list
	void AddPhysicsComponent(std::shared_ptr<PhysicsComponent> componentToAdd);

	// physics all physics components from the list
	void Physics();

	// @TODO write a function to remove the physicsing component

private:

	PhysicsEngine();

	// stores the physicscomponents
	std::list<std::weak_ptr<PhysicsComponent>> mPhysicsComponentList;

	static PhysicsEngine* sInstance;
};

