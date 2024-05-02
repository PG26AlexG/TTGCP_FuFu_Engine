#pragma once
#include "../GameCore/Utils.h"


// forward declaration
class Actor;

class Component
{
public:

	Component() = delete;
	Component(std::shared_ptr<Actor> owner);
	virtual ~Component();

	// game functions
	virtual void InitializeComponent();
	virtual void TickComponent(float deltaSeconds);

protected:

	std::shared_ptr<Actor> mOwner;
};

typedef std::list<std::shared_ptr<Component>> ComponentList;