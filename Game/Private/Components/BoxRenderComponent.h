#pragma once
#include "RendererComponent.h"


class BoxRenderComponent : public RendererComponent
{

public:

	BoxRenderComponent() = delete;
	BoxRenderComponent(std::shared_ptr<Actor> owner, exColor colour, float width, float height);

	virtual void Render(exEngineInterface* engineInterface);

private:

	float mWidth;
	float mHeight;
};

