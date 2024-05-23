#include "Line.h"

Line::Line(exColor lineColour, exVector2 start, exVector2 end)
{
	mStart = start;
	mEnd = end;
	mLineColour = lineColour;
}

void Line::BeginPlay()
{
}

void Line::InitializeActor(const exVector2 spawnPosition)
{
	Actor::InitializeActor(spawnPosition);

	AddComponentOfType<LineRenderComponent>(mLineColour, mStart, mEnd);
	AddComponentOfType<CircleColliderPhysicsComponent>(10, exVector2(0, 1));
	// @TODO line collider
}

void Line::SetVelocity(const exVector2 newVelocity)
{
	std::shared_ptr<PhysicsComponent> physicsComp = FindComponentOfType<PhysicsComponent>();

	if (physicsComp)
	{
		physicsComp->SetVelocity(newVelocity);
	}
}
