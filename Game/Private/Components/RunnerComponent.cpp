#include "RunnerComponent.h"
#include "Game/Private/Actors/Actor.h"
std::shared_ptr<Input> Input::instance;

RunnerComponent::RunnerComponent(std::shared_ptr<Actor> owner, float jumpForce) : Component(owner)
{
    mJumpForce = jumpForce;
}

void RunnerComponent::InitializeComponent()
{
    mPhysics = mOwner->FindComponentOfType<PhysicsComponent>();
}

void RunnerComponent::TickComponent(float deltaSeconds)
{
    // Check if runner should jump
    if ( (Input::GetInstance()->GetUpDown()) )
    {
        InitiateJump();
    }
}

void RunnerComponent::InitiateJump()
{
    mPhysics->AddVelocity( exVector2(0, -mJumpForce) );
}

