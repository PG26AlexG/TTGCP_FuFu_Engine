#pragma once
#include "PhysicsComponent.h"


class CircleColliderPhysicsComponent : public PhysicsComponent
{
public:

	CircleColliderPhysicsComponent() = delete;

	CircleColliderPhysicsComponent(std::shared_ptr<Actor> owner, float radius, exVector2 velocity);

protected:

	bool IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent) override;

	float mRadius;
};

