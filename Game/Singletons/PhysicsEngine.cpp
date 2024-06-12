#include "PhysicsEngine.h"
#include "Game/Private/Components/PhysicsComponent.h"

PhysicsEngine* PhysicsEngine::sInstance = nullptr;


PhysicsEngine* PhysicsEngine::GetInstance()
{
    if (!sInstance)
    {
        sInstance = new PhysicsEngine();
    }

    return sInstance;
}

void PhysicsEngine::AddPhysicsComponent(std::shared_ptr<PhysicsComponent> componentToAdd)
{
    mPhysicsComponentList.push_back(componentToAdd);
}

void PhysicsEngine::Physics()
{
    for (std::weak_ptr<PhysicsComponent> componentToPhysics : mPhysicsComponentList)
    {
        if (!componentToPhysics.expired())
        {
            componentToPhysics.lock()->Physics();

            for (std::weak_ptr<PhysicsComponent> otherPhysicsComponent : mPhysicsComponentList)
            {
                if (!otherPhysicsComponent.expired())
                {
                    if (otherPhysicsComponent.lock() != componentToPhysics.lock())
                    {
                        if (componentToPhysics.lock()->IsCollisionDetected(otherPhysicsComponent.lock()))
                        {
                            // @TODO change resolution based on requirement
                            if (!componentToPhysics.lock()->mIsStatic)
                            {
                                const exVector2 newVelocity = (componentToPhysics.lock()->GetVelocity() * -0.1f) - exVector2(0.0f, componentToPhysics.lock()->weight);
                                componentToPhysics.lock()->SetVelocity(newVelocity);
                            }

                            // call collision events
                            for (CollisionEventSignature& collisionEvent : componentToPhysics.lock()->mCollisionEvents)
                            {
                                // @TODO write function to calculate the normal
                                collisionEvent(exVector2(0, 0), otherPhysicsComponent.lock()->GetOwner(), otherPhysicsComponent);
                            }
                        }
                    }
                }
            }
        }
    }
}

PhysicsEngine::PhysicsEngine()
{
}
