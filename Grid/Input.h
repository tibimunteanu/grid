#pragma once

#include <SDL.h>

class Input
{
private:
    static Input* sInstance;

    const Uint8* mKeyboardStates;

public:
    static Input* Instance();
    static void Release();

    bool KeyDown(SDL_Scancode scanCode);

    void Update();

private:
    Input();
    ~Input();
};
