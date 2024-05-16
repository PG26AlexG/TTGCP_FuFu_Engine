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
        }
    }
}

PhysicsEngine::PhysicsEngine()
{
}
