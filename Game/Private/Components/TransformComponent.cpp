#include "TransformComponent.h"

TransformComponent::TransformComponent(exVector2 location, std::shared_ptr<Actor> owner) :
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
