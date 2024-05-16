#include "RenderEngine.h"
#include "Game/Private/Components/RendererComponent.h"

// always initialize static variables
RenderEngine* RenderEngine::sInstance = nullptr;

RenderEngine* RenderEngine::GetInstance()
{
    if (!sInstance)
    {
        sInstance = new RenderEngine();
    }

    return sInstance;
}

void RenderEngine::AddRenderingComponent(std::shared_ptr<RendererComponent> componentToAdd)
{
    mRenderComponentList.push_back(componentToAdd);
}

void RenderEngine::Render(exEngineInterface* engineInterface)
{
    for (std::weak_ptr<RendererComponent> componentToRender : mRenderComponentList)
    {
        if (!componentToRender.expired())
        {
            componentToRender.lock()->Render(engineInterface);
        }
    }
}

RenderEngine::RenderEngine()
{
}
