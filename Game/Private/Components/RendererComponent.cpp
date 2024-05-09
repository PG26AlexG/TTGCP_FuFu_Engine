#include "RendererComponent.h"

RendererComponent::RendererComponent(std::shared_ptr<Actor> owner, exColor colour) :
	Component(owner),
	mColour(colour)
{
}

exColor RendererComponent::GetColour() const
{
	return mColour;
}

void RendererComponent::SetColour(exColor inColour)
{
	mColour = inColour;
}
