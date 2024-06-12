#include "RunnerComponent.h"
#include "Game/Private/Actors/Actor.h"
std::shared_ptr<Input> Input::instance;

RunnerComponent::RunnerComponent(std::shared_ptr<Actor> owner, float jumpForce) : Component(owner)
{
    mJumpForce = jumpForce;
}

void RunnerComponent::InitializeComponent()
{
    CollisionEventSignature collisionDelegate = std::bind(&RunnerComponent::CheckIsGrounded, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    mOwner->FindComponentOfType<PhysicsComponent>()->ListenForCollision(collisionDelegate);
    mPhysics = mOwner->FindComponentOfType<PhysicsComponent>();
}

void RunnerComponent::TickComponent(float deltaSeconds)
{
    // Check if runner should jump
    if ((Input::GetInstance()->GetUpDown()) && !mIsJumping)
    {
        InitiateJump();
    }
}

void RunnerComponent::InitiateJump()
{
    mIsJumping = true;
    mPhysics->AddVelocity(exVector2(0, -mJumpForce * 3));
}

void RunnerComponent::CheckIsGrounded(exVector2 pos, std::weak_ptr<Actor> actor, std::weak_ptr<PhysicsComponent> pc)
{
    mIsJumping = false;
}

