#include "CircleRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Private/Actors/Actor.h"

CircleRenderComponent::CircleRenderComponent(std::shared_ptr<Actor> owner, exColor colour, float radius) :
	RendererComponent(owner, colour),
	mRadius(radius)
{
}

void CircleRenderComponent::Render(exEngineInterface* engineInterface)
{
	std::shared_ptr<TransformComponent> transformComp = mOwner->FindComponentOfType<TransformComponent>();

	if (!transformComp)
	{
		return;
	}

	const exVector2 centerPosition = transformComp->GetPosition();

	// @todo add support for layering in the render component

	engineInterface->DrawCircle(centerPosition, mRadius, mColour, 1);
}
