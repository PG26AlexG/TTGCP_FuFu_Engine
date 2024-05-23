//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"

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

	GameDesignersHead = WORLD->SpawnActorOfClass<Football>(exVector2{ 700.0f, 400.0f }, exColor{ 255, 255, 0, 255 }, 50.0f);

	
	//HenrysHead = WORLD->SpawnActorOfClass<Football>(exVector2{ 100.0f, 400.0f }, exColor{ 255, 255, 0, 255 }, 150.0f);

	GameDesignersTorso = WORLD->SpawnActorOfClass<Box>(exVector2{ 500.0f, 400.0f }, exColor{ 0, 255, 0, 255 }, 250.0f, 100.0f);

	GameDesignersLeftLeg = WORLD->SpawnActorOfClass<Line>(exVector2{ 200.0f, 400.0f }, exColor{ 0, 0, 0, 255 }, exVector2{ 200.0f, 400.0f }, exVector2{ 400.0f, 400.0f });
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
	if (mUp)
	{
		GameDesignersHead->SetVelocity(exVector2(-1, 0));
		GameDesignersTorso->SetVelocity(exVector2(1, 0));
		GameDesignersLeftLeg->SetVelocity(exVector2(0, -1));
		mTextPosition.y -= 40.0f * fDeltaT;
	}
	else if (mDown)
	{
		GameDesignersHead->SetVelocity(exVector2(0, 1));
		GameDesignersTorso->SetVelocity(exVector2(0, 1));
		GameDesignersLeftLeg->SetVelocity(exVector2(0, 1));
		mTextPosition.y += 40.0f * fDeltaT;
	}

	exVector2 p1, p2;
	exColor c;
	float r;

	c.mColor[0] = 255;
	c.mColor[1] = 0;
	c.mColor[2] = 255;
	c.mColor[3] = 255;

	p1.x = 175.0f;
	p1.y = 175.0f;

	r = 25.0f;

	mEngine->DrawLineCircle(p1, r, c, 0);

	// in class draw elements
	// params ({position}, {radius}, {colour}, {z-index})
	//mEngine->DrawCircle({(kViewportWidth * 0.5f), (kViewportHeight * 0.5f)}, 50, {255, 0, 0, 255}, 1);
	float length = 100;
	mEngine->DrawLine({ (kViewportWidth * 0.5f - length), (kViewportHeight * 0.5f) }, { (kViewportWidth * 0.5f + length), (kViewportHeight * 0.5f) }, { 0, 0, 0, 255 }, 1);

	p1.x = 100.0f;
	p1.y = 100.0f;

	p2.x = 200.0f;
	p2.y = 200.0f;

	c.mColor[0] = 255;
	c.mColor[1] = 0;
	c.mColor[2] = 0;

	mEngine->DrawBox(p1, p2, c, 1);

	p1.x = 400.0f;
	p1.y = 400.0f;

	p2.x = 500.0f;
	p2.y = 500.0f;

	mEngine->DrawLineBox(p1, p2, c, 1);

	p1.x = 400.0f;
	p1.y = 400.0f;

	c.mColor[0] = 0;
	c.mColor[1] = 0;
	c.mColor[2] = 0;

	mEngine->DrawCircle(p1, r, c, 2);

	mEngine->DrawText(mFontID, mTextPosition, "VFS", c, 0);
	
	if (mEngine)
	{
		RENDER_ENGINE->Render(mEngine);
	}

	/*if (std::shared_ptr<PhysicsComponent> physicsComponent = GameDesignersHead->FindComponentOfType<PhysicsComponent>())
	{
		physicsComponent->Physics();
	}*/

	PHYSICS_ENGINE->Physics();
}
