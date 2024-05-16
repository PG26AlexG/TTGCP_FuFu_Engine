#pragma once
#include "Component.h"
#include "Engine/Public/EngineTypes.h"

class exEngineInterface;

class RendererComponent : public Component,
						  public std::enable_shared_from_this<RendererComponent>
{
public:

	RendererComponent() = delete;
	RendererComponent(std::shared_ptr<Actor> owner, exColor colour);

	virtual void InitializeComponent();

	virtual void Render(exEngineInterface* engineInterface) = 0;

	// Getter
	exColor GetColour() const;
	// Setters
	void SetColour(exColor inColour);

protected:

	exColor mColour;
};