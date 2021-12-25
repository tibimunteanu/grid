#pragma once

#include "Timer.h"
#include "Input.h"
#include "Audio.h"

class App
{
public:
    const int FRAME_RATE = 60;


private:
    static App* sInstance;
    static bool sInitialized;

public:
    static App* Instance();
    static void Release();


private:
    bool mQuit;

    Graphics* mGraphics;
    Assets* mAssets;
    Input* mInput;
    Audio* mAudio;
    Timer* mTimer;

    SDL_Event mEvents;

private:
    App();
    ~App();

    void EarlyUpdate();
    void Update();
    void LateUpdate();

    void Render();

public:
    void Run();
};
