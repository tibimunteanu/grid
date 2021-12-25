#include "App.h"

// static
App* App::sInstance = NULL;
bool App::sInitialized = false;

App* App::Instance()
{
    if (sInstance == NULL)
    {
        sInstance = new App();
        if (!sInitialized)
        {
            Release();
        }
    }
    return sInstance;
}

void App::Release()
{
    if (sInstance)
    {
        delete sInstance;
        sInstance = NULL;
    }

    sInitialized = false;
}


// private
App::App()
{
    mQuit = false;
    mGraphics = NULL;
    mAssets = NULL;
    mInput = NULL;
    mAudio = NULL;
    mTimer = NULL;
    mEvents = {};

    mGraphics = Graphics::Instance();
    if (!mGraphics)
    {
        return;
    }

    mAssets = Assets::Instance();
    if (!mAssets)
    {
        return;
    }

    mInput = Input::Instance();
    if (!mInput)
    {
        return;
    }

    mAudio = Audio::Instance();
    if (!mAudio)
    {
        return;
    }

    mTimer = Timer::Instance();
    if (!mTimer)
    {
        return;
    }

    sInitialized = true;
}

App::~App()
{
    Audio::Release();
    mAudio = NULL;

    Assets::Release();
    mAssets = NULL;

    Graphics::Release();
    mGraphics = NULL;

    Input::Release();
    mInput = NULL;

    Timer::Release();
    mTimer = NULL;
}


void App::EarlyUpdate()
{
    mTimer->Reset();
    mInput->Update();

    //add early updating here
}

void App::Update()
{
    // add updating here
}

void App::LateUpdate()
{
    //add late updating here

    mInput->UpdatePrevInput();
}

void App::Render()
{
    mGraphics->ClearBackBuffer();

    // add rendering here

    mGraphics->Render();
}


// public API
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
            EarlyUpdate();
            Update();
            LateUpdate();

            Render();
        }
    }
}
