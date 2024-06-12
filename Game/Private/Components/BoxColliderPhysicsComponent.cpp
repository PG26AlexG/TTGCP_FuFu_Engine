#include "BoxColliderPhysicsComponent.h"
#include "TransformComponent.h"
#include "Game/Private/Actors/Actor.h"
#include "math.h"

BoxColliderPhysicsComponent::BoxColliderPhysicsComponent(std::shared_ptr<Actor> owner, float width, float height, exVector2 velocity)
	:PhysicsComponent(owner, false, true, velocity)
{
	mWidth = width;
	mHeight = height;
}

bool BoxColliderPhysicsComponent::IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent)
{
	if (!otherComponent)
	{
		return false;
	}

	if (std::shared_ptr<BoxColliderPhysicsComponent> otherBoxColliderComponent = std::dynamic_pointer_cast<BoxColliderPhysicsComponent>(otherComponent))
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

		const float distX = abs(distanceVector.x);
		const float distY = abs(distanceVector.y);

		bool result = (distX < mWidth / 2 + otherBoxColliderComponent->mWidth / 2 && distY < mHeight / 2 + otherBoxColliderComponent->mHeight / 2);

		return (distX < mWidth / 2 + otherBoxColliderComponent->mWidth / 2 && distY < mHeight / 2 + otherBoxColliderComponent->mHeight / 2);
	}

	return false;
}

