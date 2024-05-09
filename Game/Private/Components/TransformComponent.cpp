#include "TransformComponent.h"

TransformComponent::TransformComponent(std::shared_ptr<Actor> owner, exVector2 location) :
    Component(owner),
    mLocation(location)
{
}

exVector2 TransformComponent::GetPosition() const
{
    return mLocation;
}

void TransformComponent::SetPosition(const exVector2 inValue)
{
    mLocation = inValue;
}
