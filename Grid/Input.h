#pragma once

#include <SDL.h>
#include "Math.h"

class Input
{
public:
    enum MOUSE_BUTTON { left = 0, right, middle, back, forward };


private:
    static Input* sInstance;
    static bool sInitialized;

public:
    static Input* Instance();
    static void Release();


private:
    const Uint8* mKeyboardState;
    const Uint8* mPrevKeyboardState;
    int mKeyLength;

    Uint32 mMouseState;
    Uint32 mPrevMouseState;
    int mMouseX;
    int mMouseY;

private:
    Input();
    ~Input();

    Uint32 GetMouseMask(MOUSE_BUTTON button);

public:
    bool KeyDown(SDL_Scancode scanCode);
    bool KeyPressed(SDL_Scancode scanCode);
    bool KeyUp(SDL_Scancode scanCode);

    Vector2 MousePos();
    bool MouseButtonDown(MOUSE_BUTTON button);
    bool MouseButtonPressed(MOUSE_BUTTON button);
    bool MouseButtonUp(MOUSE_BUTTON button);

    void Update();
    void UpdatePrevInput();
};
