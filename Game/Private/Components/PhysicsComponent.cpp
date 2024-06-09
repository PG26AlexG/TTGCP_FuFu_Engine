#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "Game/Private/Actors/Actor.h"
#include "Game/Singletons/PhysicsEngine.h"

PhysicsComponent::PhysicsComponent(std::shared_ptr<Actor> owner, bool isStatic, bool isGravityEnabled, exVector2 velocity) : Component(owner)
{
	mIsStatic = isStatic;
	mIsGravityEnabled = isGravityEnabled;
	mVelocity = velocity;
}

void PhysicsComponent::Physics()
{
	if (mOwner)
	{
		if (mIsStatic)
		{
			return;
		}
		if (std::shared_ptr<TransformComponent> transformComponent = mOwner->FindComponentOfType<TransformComponent>())
		{
			const exVector2 newPosition = transformComponent->GetPosition() + mVelocity;
			// @TODO add gravity
			transformComponent->SetPosition(newPosition);

			if (mIsGravityEnabled)
			{
				
			}
		}
	}
}

void PhysicsComponent::InitializeComponent()
{
	Component::InitializeComponent();

	PHYSICS_ENGINE->AddPhysicsComponent(shared_from_this());
}

exVector2 PhysicsComponent::GetVelocity() const
{
	return mVelocity;
}

void PhysicsComponent::SetVelocity(const exVector2 inVelocity)
{
	mVelocity = inVelocity;
}

void PhysicsComponent::AddVelocity (const exVector2 inVelocity)
{
	mVelocity.x += inVelocity.x;
	mVelocity.y += inVelocity.y;
}

bool PhysicsComponent::IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent)
{
	return false;
}

void PhysicsComponent::ListenForCollision(CollisionEventSignature& delegateToAdd)
{
	mCollisionEvents.push_back(delegateToAdd);
}
