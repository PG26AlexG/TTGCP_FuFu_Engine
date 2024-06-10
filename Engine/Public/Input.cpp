#include "Input.h"

#include <iostream>
#include <windows.h>

#include "Engine/Public/SDL.h"

std::shared_ptr<Input> Input::GetInstance()
{
    if (instance)
    {
        return instance;
    }

    instance = std::make_shared<Input>();
    return instance;
}

int Input::GetCurrentKeysDown() const
{
    return mInputs;
}

bool Input::GetUpDown()
{
    return (mInputs & UP);
}

bool Input::GetDownDown()
{
    return (GetCurrentKeysDown() & DOWN);

}

bool Input::GetLeftDown()
{
    return (GetCurrentKeysDown() & LEFT);

}

bool Input::GetRightDown()
{
    return (GetCurrentKeysDown() & RIGHT);

}

bool Input::GetConfirmDown()
{
    return (GetCurrentKeysDown() & CONFIRM);

}

void Input::CheckCurrentInputs()
{
    int keysDown = 0;
    const Uint8* state = SDL_GetKeyboardState(&keysDown);

    if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_SPACE])
    {
        mInputs = mInputs | UP;
        std::cout << "UP";
    }
    
    if (state[SDL_SCANCODE_A])
    {
        mInputs = mInputs | LEFT;
    }
    
    if (state[SDL_SCANCODE_S])
    {
        mInputs = mInputs | DOWN;
    }
    
    if (state[SDL_SCANCODE_D])
    {
        mInputs = mInputs | RIGHT;
    }
    
    if (state[SDL_SCANCODE_KP_ENTER])
    {
        mInputs = mInputs | CONFIRM;
    }
}

void Input::ClearCurrentInputs()
{
    mInputs = 0;
}
