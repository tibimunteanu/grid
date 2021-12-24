#include "App.h"

App* App::sInstance = NULL;

App* App::Instance()
{
    if (sInstance == NULL)
    {
        sInstance = new App();
    }
    return sInstance;
}

void App::Release()
{
    delete sInstance;
    sInstance = NULL;
}

App::App()
{
    mQuit = false;

    mGraphics = Graphics::Instance();

    if (!Graphics::Initialized())
    {
        mQuit = true;
    }

    mTimer = Timer::Instance();
}

App::~App()
{
    Graphics::Release();
    mGraphics = NULL;

    Timer::Release();
    mTimer = NULL;
}

void App::Run()
{
    while (!mQuit)
    {
        mTimer->Update();

        while (SDL_PollEvent(&mEvents) != 0)
        {
            if (mEvents.type == SDL_QUIT)
            {
                mQuit = true;
            }
        }

        if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE)
        {
            printf("dt: %F\n", mTimer->DeltaTime());

            mGraphics->Render();

            mTimer->Reset();
        }
    }
}
