#include "TimerComponent.h"

TimerComponent::TimerComponent(std::shared_ptr<Actor> owner) : Component(owner)
{
}

void TimerComponent::InitializeComponent()
{
	if (mInstance == nullptr)
	{
	}

	mInstance = this;
}

void TimerComponent::TickComponent(float deltaSeconds) 
{
	std::cout << "SECONDS " <<  deltaSeconds;
	elapsedTime += deltaSeconds;
}

TimerComponent* TimerComponent::GetInstance()
{
	return mInstance;
}
