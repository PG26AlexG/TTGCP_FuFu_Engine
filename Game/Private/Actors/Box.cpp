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
	AddComponentOfType<BoxColliderPhysicsComponent>(mWidth, mHeight, exVector2(0, 0));
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

void Box::OnCollisionDetected(exVector2 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent)
{
	std::shared_ptr<RendererComponent> renderComp = FindComponentOfType<RendererComponent>();

	if (renderComp)
	{
		renderComp->SetColour(exColor{ 0, 255, 0, 255 });
	}
}
