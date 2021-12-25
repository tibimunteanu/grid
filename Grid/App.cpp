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

    mAssets = Assets::Instance();

    mInput = Input::Instance();

    mTimer = Timer::Instance();

    mTex = new Texture("Hello World!", "UbuntuMono-Regular.ttf", 72);
    mTex->Pos(Vector2(400.0f, 200.0f));
}

App::~App()
{
    Assets::Release();
    mAssets = NULL;

    Graphics::Release();
    mGraphics = NULL;

    Input::Release();
    mInput = NULL;

    Timer::Release();
    mTimer = NULL;

    delete mTex;
    mTex = NULL;
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
            mInput->Update();
            mTex->Update();

            mGraphics->ClearBackBuffer();
            mTex->Render();
            mGraphics->Render();

            mTimer->Reset();
        }
    }
}
