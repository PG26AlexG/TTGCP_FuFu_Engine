#pragma once
#include "Component.h"
#include "PhysicsComponent.h"
#include "Engine/Public/Input.h"

class RunnerComponent : Component
{
public:
    // game functions
    virtual void InitializeComponent() override;
    virtual void TickComponent(float deltaSeconds) override;

private:
    // member variables
    std::shared_ptr<PhysicsComponent> mPhysics;

    void InitiateJump();
    
    // parameters
    float mJumpForce = 5;
};
