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

void DrawAsync(std::list<std::weak_ptr<RendererComponent>> mRenderComponentList, exEngineInterface* engineInterface)
{
    for (std::weak_ptr<RendererComponent> componentToRender : mRenderComponentList)
    {
        if (!componentToRender.expired())
        {
            componentToRender.lock()->Render(engineInterface);
        }
    }
}

void RenderEngine::Render(exEngineInterface* engineInterface)
{
    std::list<std::weak_ptr<RendererComponent>> componentList = mRenderComponentList;
       
    std::thread drawAsync(DrawAsync, mRenderComponentList, engineInterface);

    drawAsync.join();
}

RenderEngine::RenderEngine()
{
}
