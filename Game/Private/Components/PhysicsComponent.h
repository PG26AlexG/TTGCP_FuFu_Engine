#pragma once
#include "Game/Private/Components/Component.h"
#include "Engine/Public/EngineTypes.h"


class PhysicsComponent : public Component,
	                     public std::enable_shared_from_this<PhysicsComponent>
{
public:

	PhysicsComponent() = delete;
	PhysicsComponent(std::shared_ptr<Actor> owner, bool isStatic, bool isGravityEnabled, exVector2 velocity);

	// @TODO
	// float GetSpeed() const

	// Physics Function

	virtual void Physics();

	virtual void InitializeComponent();

	// Getters and Setters
	exVector2 GetVelocity() const;
	void SetVelocity(const exVector2 inVelocity);

	virtual bool IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent);

protected:

	bool mIsStatic;
	bool mIsGravityEnabled;

	exVector2 mVelocity;


};

