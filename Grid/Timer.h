#pragma once

#include <SDL.h>

class Timer
{
private:
    static Timer* sInstance;
    static bool sInitialized;

public:
    static Timer* Instance();
    static void Release();


private:
    unsigned int mStartTicks;
    unsigned int mElapsedTicks;
    float mDeltaTime;
    float mTimeScale;

private:
    Timer();
    ~Timer();

public:
    void Reset();

    float DeltaTime();

    void TimeScale(float t = 1.0f);
    float TimeScale();

    void Update();
};
