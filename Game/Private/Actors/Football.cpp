#include "Football.h"

Football::Football(exColor ballColour, float radius)
{
	mRadius = radius;
	mBallColour = ballColour;
}

void Football::BeginPlay()
{
}

void Football::InitializeActor(const exVector2 spawnPosition)
{
	Actor::InitializeActor(spawnPosition);

	AddComponentOfType<CircleRenderComponent>(mBallColour, mRadius);
	std::shared_ptr<CircleColliderPhysicsComponent> colliderComp = AddComponentOfType<CircleColliderPhysicsComponent>(mRadius, exVector2(0, 1));
	CollisionEventSignature collisionDelegate = std::bind(&Football::OnCollisionDetected, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	colliderComp->ListenForCollision(collisionDelegate);
}

void Football::SetVelocity(const exVector2 newVelocity)
{
	std::shared_ptr<PhysicsComponent> physicsComp = FindComponentOfType<PhysicsComponent>();

	if (physicsComp)
	{
		physicsComp->SetVelocity(newVelocity);
	}
}

void Football::OnCollisionDetected(exVector2 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent)
{
	std::shared_ptr<RendererComponent> renderComp = FindComponentOfType<RendererComponent>();

	if (renderComp)
	{
		renderComp->SetColour(exColor{ 0, 255, 0, 255 });
	}
}
