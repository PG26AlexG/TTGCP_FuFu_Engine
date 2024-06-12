#pragma once
#include "Component.h"
#include "PhysicsComponent.h"
#include "memory"
class ObsticleCompoent :
    public Component
{
public:
	ObsticleCompoent(std::shared_ptr<Actor> owner);

	// game functions
	virtual void InitializeComponent();
	virtual void TickComponent(float deltaSeconds);

	void DeathEffect(exVector2 pos, std::weak_ptr<Actor> actor, std::weak_ptr<PhysicsComponent> pc);

private:
	std::shared_ptr<PhysicsComponent> pc;
};

