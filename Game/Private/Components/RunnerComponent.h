#pragma once
#include "Component.h"
#include "PhysicsComponent.h"
#include "Engine/Public/Input.h"

class RunnerComponent :
public Component,
public std::enable_shared_from_this<RunnerComponent>
{
public:
    // Constructors
    RunnerComponent() = delete;
    RunnerComponent(std::shared_ptr<Actor> owner, float jumpForce);
    
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
