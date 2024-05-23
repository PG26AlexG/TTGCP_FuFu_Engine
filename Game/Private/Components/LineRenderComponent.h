#pragma once
#include "RendererComponent.h"
class LineRenderComponent : public RendererComponent
{
public:

	LineRenderComponent() = delete;
	LineRenderComponent(std::shared_ptr<Actor> owner, exColor colour, exVector2 start, exVector2 end);

	virtual void Render(exEngineInterface* engineInterface);

private:

	exVector2 mStart;
	exVector2 mEnd;
};