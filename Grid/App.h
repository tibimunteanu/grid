#pragma once

#include "Graphics.h"
#include "Timer.h"

class App
{
private:
    static App* sInstance;

    const int FRAME_RATE = 60;

    bool mQuit;
    Graphics* mGraphics;

    Timer* mTimer;

    SDL_Event mEvents;

public:
    static App* Instance();
    static void Release();

    void Run();

private:
    App();
    ~App();
};
