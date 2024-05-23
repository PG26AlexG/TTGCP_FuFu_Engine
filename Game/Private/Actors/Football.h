#pragma once

#include "Game/Private/Actors/Actor.h"
#include "Engine/Public/EngineTypes.h"

class Football : public Actor
{
public:

	Football(exColor ballColour, float radius);

	virtual void BeginPlay() override;

	virtual void InitializeActor(const exVector2 spawnPosition) override;

	virtual void SetVelocity(const exVector2 newVelocity);

	void OnCollisionDetected(exVector2 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent);

private:

	exColor mBallColour;
	float mRadius;
};

