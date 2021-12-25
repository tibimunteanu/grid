#include "Input.h"
#include <string.h>

// static
Input* Input::sInstance = NULL;
bool Input::sInitialized = false;

Input* Input::Instance()
{
    if (sInstance == NULL)
    {
        sInstance = new Input();
        if (!sInitialized)
        {
            Release();
        }
    }
    return sInstance;
}


void Input::Release()
{
    if (sInstance)
    {
        delete sInstance;
        sInstance = NULL;
    }

    sInitialized = false;
}


// private
Input::Input()
{
    mKeyboardState = SDL_GetKeyboardState(&mKeyLength);
    mPrevKeyboardState = new Uint8[mKeyLength];

    memcpy((void*)mPrevKeyboardState, mKeyboardState, mKeyLength);

    mMouseState = 0;
    mPrevMouseState = 0;
    mMouseX = 0;
    mMouseY = 0;

    sInitialized = true;
}

Input::~Input()
{
    delete[] mPrevKeyboardState;
    mPrevKeyboardState = NULL;
}


Uint32 Input::GetMouseMask(MOUSE_BUTTON button)
{
    switch (button)
    {
        case left: return SDL_BUTTON_LMASK;
        case right: return SDL_BUTTON_RMASK;
        case middle: return SDL_BUTTON_MMASK;
        case back: return SDL_BUTTON_X1MASK;
        case forward: return SDL_BUTTON_X2MASK;
        default: return 0;
    }
}


// public API
bool Input::KeyDown(SDL_Scancode scanCode)
{
    return mKeyboardState[scanCode];
}

bool Input::KeyPressed(SDL_Scancode scanCode)
{
    return !mPrevKeyboardState[scanCode] && mKeyboardState[scanCode];
}

bool Input::KeyUp(SDL_Scancode scanCode)
{
    return mPrevKeyboardState[scanCode] && !mKeyboardState[scanCode];
}


Vector2 Input::MousePos()
{
    return Vector2((float)mMouseX, (float)mMouseY);
}

bool Input::MouseButtonDown(MOUSE_BUTTON button)
{
    return mMouseState & GetMouseMask(button);
}

bool Input::MouseButtonPressed(MOUSE_BUTTON button)
{
    Uint8 mask = GetMouseMask(button);
    return !(mPrevMouseState & mask) && (mMouseState & mask);
}

bool Input::MouseButtonUp(MOUSE_BUTTON button)
{
    Uint8 mask = GetMouseMask(button);
    return (mPrevMouseState & mask) && !(mMouseState & mask);
}


void Input::Update()
{
    mMouseState = SDL_GetMouseState(&mMouseX, &mMouseY);
}

void Input::UpdatePrevInput()
{
    memcpy((void*)mPrevKeyboardState, mKeyboardState, mKeyLength);
    mPrevMouseState = mMouseState;
}
