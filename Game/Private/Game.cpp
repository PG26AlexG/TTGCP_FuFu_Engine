//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"

#include "Components/RunnerComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include "Game/Private/GameCore/ActorTypes.h"
#include "Game/Private/GameCore/ComponentTypes.h"
#include "Game/Singletons/RenderEngine.h"
#include "Game/Singletons/PhysicsEngine.h"
#include "Game/Singletons/WorldManager.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Definitely not malware :3";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mEngine(nullptr)
	, mFontID(-1)
	, mUp(false)
	, mDown(false)
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize(exEngineInterface* pEngine)
{
	mEngine = pEngine;

	mFontID = mEngine->LoadFont("Resources/BlackOpsOne-Regular.ttf", 32);

	mTextPosition.x = 50.0f;
	mTextPosition.y = 50.0f;

	Runner = WORLD->SpawnActorOfClass<Football>(exVector2{ 700.0f, 400.0f }, exColor{ 255, 255, 0, 255 }, 50.0f);

	Runner->AddComponentOfType<RunnerComponent>(5);
	Runner->SetVelocity(exVector2(0,0));
	//HenrysHead = WORLD->SpawnActorOfClass<Football>(exVector2{ 100.0f, 400.0f }, exColor{ 255, 255, 0, 255 }, 150.0f);

	Ground = WORLD->SpawnActorOfClass<Box>(exVector2{ 500.0f, 600.0f }, exColor{ 0, 255, 0, 255 }, 1000.0f, 100.0f);
	Ground->SetVelocity(exVector2(0,0));
	Ground->FindComponentOfType<PhysicsComponent>()->SetGravityEnabled(false);
	
	//GameDesignersLeftLeg = WORLD->SpawnActorOfClass<Line>(exVector2{ 200.0f, 400.0f }, exColor{ 0, 0, 0, 255 }, exVector2{ 200.0f, 400.0f }, exVector2{ 400.0f, 400.0f });
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor(exColor& color) const
{
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent(SDL_Event* pEvent)
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
	int nKeys = 0;
	const Uint8* pState = SDL_GetKeyboardState(&nKeys);

	mUp = pState[SDL_SCANCODE_UP];
	mDown = pState[SDL_SCANCODE_DOWN];
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run(float fDeltaT)
{
	Input::GetInstance()->CheckCurrentInputs();


	if (mEngine)
	{
		RENDER_ENGINE->Render(mEngine);

		PHYSICS_ENGINE->Physics();
	}

	if (WORLD)
	{
		WORLD->TickActors(fDeltaT);
	}

	Input::GetInstance()->ClearCurrentInputs();
}
