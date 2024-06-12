#pragma once
#include "Component.h"

#define TIMER TimerComponent::GetInstance()

class TimerComponent :
    public Component
{
public:
	TimerComponent() = delete;
	TimerComponent(std::shared_ptr<Actor> owner);
	// game functions
	virtual void InitializeComponent() override;
	virtual void TickComponent(float deltaSeconds) override;

	static TimerComponent* GetInstance();
	float elapsedTime = 0;

private:

	static TimerComponent* mInstance;
};

