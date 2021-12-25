#pragma once

#include "Timer.h"
#include "Texture.h"
#include "Input.h"
#include "Audio.h"

class App
{
private:
    static App* sInstance;

    const int FRAME_RATE = 60;

    bool mQuit;
    Graphics* mGraphics;
    Assets* mAssets;
    Input* mInput;
    Audio* mAudio;
    Timer* mTimer;

    SDL_Event mEvents;

    Texture* mTex;
    Texture* mTex2;
public:
    static App* Instance();
    static void Release();

    void Run();

private:
    App();
    ~App();
};
