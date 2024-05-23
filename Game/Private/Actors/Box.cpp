#include "Box.h"

Box::Box(exColor boxColour, float width, float height)
{
	mWidth = width;
	mHeight = height;
	mBoxColour = boxColour;
}

void Box::BeginPlay()
{
}

void Box::InitializeActor(const exVector2 spawnPosition)
{
	Actor::InitializeActor(spawnPosition);

	AddComponentOfType<BoxRenderComponent>(mBoxColour, mWidth, mHeight);
	AddComponentOfType<CircleColliderPhysicsComponent>(mWidth / 2, exVector2(0, 1));
	// @TODO square collider
}

void Box::SetVelocity(const exVector2 newVelocity)
{
	std::shared_ptr<PhysicsComponent> physicsComp = FindComponentOfType<PhysicsComponent>();

	if (physicsComp)
	{
		physicsComp->SetVelocity(newVelocity);
	}
}
