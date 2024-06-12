#pragma once

#include "Game/Private/Actors/Actor.h"
#include "Engine/Public/EngineTypes.h"

class Box : public Actor
{
public:

	Box(exColor boxColour, float width, float height);

	virtual void BeginPlay() override;

	virtual void InitializeActor(const exVector2 spawnPosition) override;

	virtual void SetVelocity(const exVector2 newVelocity);

	void OnCollisionDetected(exVector2 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent);

private:

	exColor mBoxColour;
	float mWidth;
	float mHeight;
};

