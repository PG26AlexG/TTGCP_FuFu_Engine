#pragma once
#include "Game/Private/GameCore/Utils.h"

#define RENDER_ENGINE RenderEngine::GetInstance()

class RendererComponent;
class exEngineInterface;

class RenderEngine
{
public:

	static RenderEngine* GetInstance();

	// will add render components to render list
	void AddRenderingComponent(std::shared_ptr<RendererComponent> componentToAdd);

	// render all render components from the list
	void Render(exEngineInterface* engineInterface);

	// @TODO write a function to remove the rendering component

private:

	RenderEngine();

	// stores the rendercomponents
	std::list<std::weak_ptr<RendererComponent>> mRenderComponentList;

	static RenderEngine* sInstance;
};

