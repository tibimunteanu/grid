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

    mAudio = Audio::Instance();

    mTimer = Timer::Instance();

    mTex = new Texture("Hello World!", "UbuntuMono-Regular.ttf", 72, { 255, 0, 0 });
    mTex->Pos(Vector2(400.0f, 200.0f));
    mTex->Scale(Vector2(0.4f, 0.4f));

    mTex2 = new Texture("Grid!", "UbuntuMono-Bold.ttf", 72, { 0, 255, 0 });
    mTex2->Pos(Vector2(300.0f, 300.0f));
    mTex2->Scale(Vector2(4.0f, 4.0f));
    mTex2->Parent(mTex);
}

App::~App()
{
    Assets::Release();
    mAssets = NULL;

    Graphics::Release();
    mGraphics = NULL;

    Input::Release();
    mInput = NULL;

    Audio::Release();
    mAudio = NULL;

    Timer::Release();
    mTimer = NULL;

    delete mTex;
    mTex = NULL;

    delete mTex2;
    mTex2 = NULL;
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

            mTex->Rotate(200 * mTimer->DeltaTime());
            mTex2->Rotate(-200 * mTimer->DeltaTime());

            mGraphics->ClearBackBuffer();
            mTex->Render();
            mTex2->Render();
            mGraphics->Render();

            mTimer->Reset();
        }
    }
}
