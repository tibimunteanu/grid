#include "Input.h"

Input* Input::sInstance = NULL;


Input* Input::Instance()
{
    if (sInstance == NULL)
    {
        sInstance = new Input();
    }
    return sInstance;
}


void Input::Release()
{
    delete sInstance;
    sInstance = NULL;
}


Input::Input()
{
}

Input::~Input()
{
}


bool Input::KeyDown(SDL_Scancode scanCode)
{
    return mKeyboardStates[scanCode];
}

void Input::Update()
{
    mKeyboardStates = SDL_GetKeyboardState(NULL);
}
