#include "Component.h"

Component::Component(std::shared_ptr<Actor> owner)
	:mOwner(owner)
{
}

Component::~Component()
{
}

void Component::InitializeComponent()
{
}

void Component::TickComponent(float deltaSeconds)
{
}
