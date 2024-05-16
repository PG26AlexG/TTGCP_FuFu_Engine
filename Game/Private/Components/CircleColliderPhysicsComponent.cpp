#include "CircleColliderPhysicsComponent.h"
#include "TransformComponent.h"
#include "Game/Private/Actors/Actor.h"
#include "math.h"

CircleColliderPhysicsComponent::CircleColliderPhysicsComponent(std::shared_ptr<Actor> owner, float radius, exVector2 velocity)
	:PhysicsComponent(owner, false, true, velocity)
{
	mRadius = radius;
}

bool CircleColliderPhysicsComponent::IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent)
{
	if (!otherComponent)
	{
		return false;
	}

	if (std::shared_ptr<CircleColliderPhysicsComponent> otherCircleColliderComponent = std::dynamic_pointer_cast<CircleColliderPhysicsComponent>(otherComponent))
	{
		const std::shared_ptr<TransformComponent> currentTransformComponent = mOwner->FindComponentOfType<TransformComponent>();
		const std::shared_ptr<TransformComponent> otherTransformComponent = otherComponent->GetOwner()->FindComponentOfType<TransformComponent>();

		if (currentTransformComponent == nullptr || otherTransformComponent == nullptr)
		{
			return false;
		}

		const exVector2 currentCenter = currentTransformComponent->GetPosition();
		const exVector2 otherCenter = otherTransformComponent->GetPosition();

		const exVector2 distanceVector = currentCenter - otherCenter;

		const float distX = distanceVector.x;
		const float distY = distanceVector.y;

		const float distance = sqrt((distX * distX) + (distY * distY));

		return (distance <= (mRadius + otherCircleColliderComponent->mRadius));
	}

	return false;
}
