#include "LineRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Private/Actors/Actor.h"

LineRenderComponent::LineRenderComponent(std::shared_ptr<Actor> owner, exColor colour, exVector2 start, exVector2 end) :
	RendererComponent(owner, colour),
	mStart(start),
	mEnd(end)
{
}

void LineRenderComponent::Render(exEngineInterface* engineInterface)
{
	std::shared_ptr<TransformComponent> transformComp = mOwner->FindComponentOfType<TransformComponent>();

	if (!transformComp)
	{
		return;
	}

	const exVector2 centerPosition = transformComp->GetPosition();

	// @todo add support for layering in the render component

	engineInterface->DrawLine(mStart, mEnd, mColour, 1);
}
