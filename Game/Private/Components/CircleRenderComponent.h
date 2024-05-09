#pragma once
#include "RendererComponent.h"


class CircleRenderComponent : public RendererComponent
{

public:

	CircleRenderComponent() = delete;
	CircleRenderComponent(std::shared_ptr<Actor> owner, exColor colour, float radius);

	virtual void Render(exEngineInterface* engineInterface);

private:

	float mRadius;
};

