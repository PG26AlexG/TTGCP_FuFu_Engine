#include "RendererComponent.h"

RendererComponent::RendererComponent(exColour colour, std::shared_ptr<Actor> owner):
	Component(owner),
	mColour(colour)
{
}
