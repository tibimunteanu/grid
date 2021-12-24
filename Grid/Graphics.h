#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>

class Graphics
{
public:
    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 256;

private:
    static Graphics* sInstance;
    static bool sInitialized;

    SDL_Window* mWindow;
    SDL_Surface* mBackBuffer;

    SDL_Renderer* mRenderer;

public:
    static Graphics* Instance();
    static void Release();
    static bool Initialized();

    SDL_Texture* LoadTexture(std::string path);

    void ClearBackBuffer();

    void DrawTexture(SDL_Texture* tex);

    void Render();

private:
    Graphics();
    ~Graphics();

    bool Init();
};
