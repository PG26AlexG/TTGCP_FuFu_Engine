#include "BoxRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Private/Actors/Actor.h"

BoxRenderComponent::BoxRenderComponent(std::shared_ptr<Actor> owner, exColor colour, float width, float height) :
	RendererComponent(owner, colour),
	mWidth(width),
	mHeight(height)
{
}

void BoxRenderComponent::Render(exEngineInterface* engineInterface)
{
	std::shared_ptr<TransformComponent> transformComp = mOwner->FindComponentOfType<TransformComponent>();

	if (!transformComp)
	{
		return;
	}

	const exVector2 centerPosition = transformComp->GetPosition();

	// @todo add support for layering in the render component

	const exVector2 topLeft = { centerPosition.x - mWidth * 0.5f, centerPosition.y - mHeight * 0.5f };
	const exVector2 bottomRight = { centerPosition.x + mWidth * 0.5f, centerPosition.y + mHeight * 0.5f };

	engineInterface->DrawBox(topLeft, bottomRight, mColour, 0);
}
