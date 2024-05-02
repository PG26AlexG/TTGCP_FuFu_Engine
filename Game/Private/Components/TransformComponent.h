#pragma once
#include "Component.h"
#include "../../Engine/EngineTypes.h"


class TransformComponent : public Component
{
public:

	TransformComponent() = delete;
	TransformComponent(exVector2 location, std::shared_ptr<Actor> owner);

	exVector2 GetPosition() const;
	void SetPosition(const exVector2 inValue);

private:

	exVector2 mLocation;
	/*exVector2 mScale;
	exVector2 mRotation;*/
};