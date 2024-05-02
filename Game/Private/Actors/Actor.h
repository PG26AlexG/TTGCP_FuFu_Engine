#pragma once

#include "../GameCore/ComponentTypes.h"
#include <type_traits>


class Actor : public std::enable_shared_from_this<Actor>
{
public:

	Actor();
	~Actor();

	// overridable functions
	virtual void BeingPlay();
	virtual void EndPlay();
	virtual void Tick(float deltaSeconds);

	template<class ComponentType, typename ...Args>
	std::shared_ptr<ComponentType> AddComponentOfType(Args... arguments)
	{
		std::shared_ptr<ComponentType> newComponent = std::make_shared<ComponentType>(arguments..., shared_from_this());

		mComponents.push_back(newComponent);
		return newComponent;
	}

	template<std::derived_from<Component> ComponentTypeToFind>
	std::shared_ptr<ComponentTypeToFind> FindComponentOfType()
	{
		for (std::shared_ptr<Component> componentIterator : mComponents)
		{
			if (std::shared_ptr<ComponentTypeToFind> foundComponent = 
				std::dynamic_pointer_cast<ComponentTypeToFind>(componentIterator))
			{
				return foundComponent;
			}
		}

		return nullptr;
	}

private:

	// List of components added to the actor
	ComponentList mComponents;
};