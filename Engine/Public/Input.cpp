#include "Input.h"

std::shared_ptr<Input> Input::GetInstance()
{
    if (instance)
    {
        return instance;
    }

    instance = std::shared_ptr<Input>();
    return instance;
}

int Input::GetCurrentKeysDown() const
{
    return 0;
}

void Input::CheckCurrentInputs()
{
}

void Input::ClearCurrentInputs()
{
}
