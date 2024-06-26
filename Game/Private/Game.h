//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "Game/Private/GameCore/ComponentTypes.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class Actor;
class Football;
class Box       ;
class Line        ;

class MyGame : public exGameInterface
{
public:

	MyGame();
	virtual						~MyGame();

	virtual void				Initialize(exEngineInterface* pEngine);

	virtual const char* GetWindowName() const;
	virtual void				GetClearColor(exColor& color) const;

	virtual void				OnEvent(SDL_Event* pEvent);
	virtual void				OnEventsConsumed();

	virtual void				Run(float fDeltaT);

private:

	exEngineInterface* mEngine;

	int								mFontID;

	exVector2						mTextPosition;

	std::shared_ptr<Box>			Runner;
	std::shared_ptr<Box>			Ground;

};
