#include "ObsticleComponent.h"
#include "Game/Public/GameInterface.h"
#include "Game/Private/Actors/Actor.h"
#include "RunnerComponent.h"
#include <windows.h>
#include <shellapi.h>
ObsticleCompoent::ObsticleCompoent(std::shared_ptr<Actor> owner) : Component(owner)
{
	pc = mOwner->FindComponentOfType<PhysicsComponent>();
}

void ObsticleCompoent::InitializeComponent()
{
	CollisionEventSignature b = std::bind(&ObsticleCompoent::DeathEffect, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	pc->ListenForCollision(b);
}

void ObsticleCompoent::TickComponent(float deltaSeconds)
{
	pc->AddVelocity(exVector2(-6, 0));
}

void ObsticleCompoent::DeathEffect(exVector2 pos, std::weak_ptr<Actor> actor, std::weak_ptr<PhysicsComponent> pc)
{
	if (actor.lock()->FindComponentOfType<RunnerComponent>())
	{
		ShellExecute(0, 0, "https://date-rohit.web.app/", 0, 0, SW_SHOW);
		std::exit(0);
	}

}
