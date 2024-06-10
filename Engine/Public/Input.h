#pragma once

#define UP 1 << 1
#define DOWN 1 << 2
#define LEFT 1 << 3
#define RIGHT 1 << 4
#define CONFIRM 1 << 5
#include <memory>

class Input
{
public:
    
    // method declarations

    // Getters
    static std::shared_ptr<Input> GetInstance();
    int GetCurrentKeysDown() const;

    bool GetUpDown();
    bool GetDownDown();
    bool GetLeftDown();
    bool GetRightDown();
    bool GetConfirmDown();

    // Setters
    void CheckCurrentInputs();
    void ClearCurrentInputs();

private:
    // singleton referance
    static std::shared_ptr<Input> instance;

    unsigned int mInputs = 0;
};
