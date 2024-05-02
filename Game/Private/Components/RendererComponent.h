#pragma once
#include "Component.h"
#include "../../Engine/EngineTypes.h"

class RendererComponent : public Component
{
public:

	RendererComponent() = delete;
	RendererComponent(exColour colour, std::shared_ptr<Actor> owner);

	virtual void Render(/*TODO*/) = 0;

private:

	exColour mColour;
};