#include "Actor.h"

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::BeginPlay()
{
}

void Actor::EndPlay()
{
}

void Actor::Tick(float deltaSeconds)
{
	std::list<std::shared_ptr<Component>>::iterator it;
	for (it = mComponents.begin(); it != mComponents.end(); ++it)
	{
		// make sure it's not already a managed type
		if ( dynamic_cast< PhysicsComponent* > ( it->get() )
			|| dynamic_cast<RendererComponent*>(it->get()))
		{
			continue;
		}

		// tick a given compoentn
		it->get()->TickComponent(deltaSeconds);
	}
}

void Actor::InitializeActor(const exVector2 spawnPosition)
{
	mTransformComponent = AddComponentOfType<TransformComponent>(spawnPosition);
}
