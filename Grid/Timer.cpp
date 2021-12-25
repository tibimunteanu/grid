#include "Timer.h"

// static
Timer* Timer::sInstance = NULL;
bool Timer::sInitialized = false;

Timer* Timer::Instance()
{
    if (sInstance == NULL)
    {
        sInstance = new Timer();
        if (!sInitialized)
        {
            Release();
        }
    }
    return sInstance;
}

void Timer::Release()
{
    if (sInstance)
    {
        delete sInstance;
        sInstance = NULL;
    }

    sInitialized = false;
}


// private
Timer::Timer()
{
    Reset();
    mTimeScale = 1.0f;
    mElapsedTicks = 0;
    mDeltaTime = 0.0f;

    sInitialized = true;
}

Timer::~Timer()
{
}


// public Api
void Timer::Reset()
{
    mStartTicks = SDL_GetTicks();
}


float Timer::DeltaTime()
{
    return mDeltaTime;
}


void Timer::TimeScale(float t)
{
    mTimeScale = t;
}

float Timer::TimeScale()
{
    return mTimeScale;
}


void Timer::Update()
{
    mElapsedTicks = SDL_GetTicks() - mStartTicks;
    mDeltaTime = mElapsedTicks * 0.001f;
}
