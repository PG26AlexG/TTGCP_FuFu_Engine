#include "RendererComponent.h"
#include "Game/Singletons/RenderEngine.h"

RendererComponent::RendererComponent(std::shared_ptr<Actor> owner, exColor colour) :
	Component(owner),
	mColour(colour)
{
}

void RendererComponent::InitializeComponent()
{
	Component::InitializeComponent();

	RENDER_ENGINE->AddRenderingComponent(shared_from_this());
}

exColor RendererComponent::GetColour() const
{
	return mColour;
}

void RendererComponent::SetColour(exColor inColour)
{
	mColour = inColour;
}
