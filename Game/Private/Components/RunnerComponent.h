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
    void CheckIsGrounded(exVector2 pos, std::weak_ptr<Actor> actor, std::weak_ptr<PhysicsComponent> pc) ;
    
    // parameters
    float mJumpForce = 25;
    bool mIsJumping = false;
};
