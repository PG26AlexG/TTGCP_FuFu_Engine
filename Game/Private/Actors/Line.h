#pragma once

#include "Game/Private/Actors/Actor.h"
#include "Engine/Public/EngineTypes.h"

class Line : public Actor
{
public:

	Line(exColor lineColour, exVector2 start, exVector2 end);

	virtual void BeginPlay() override;

	virtual void InitializeActor(const exVector2 spawnPosition) override;

	virtual void SetVelocity(const exVector2 newVelocity);

private:

	exColor mLineColour;
	exVector2 mStart;
	exVector2 mEnd;
};

