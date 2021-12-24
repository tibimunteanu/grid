#pragma once

#include "Timer.h"
#include "Texture.h"

class App
{
private:
    static App* sInstance;

    const int FRAME_RATE = 60;

    bool mQuit;
    Graphics* mGraphics;
    Assets* mAssets;
    Timer* mTimer;

    SDL_Event mEvents;

    Texture* mTex;
public:
    static App* Instance();
    static void Release();

    void Run();

private:
    App();
    ~App();
};
