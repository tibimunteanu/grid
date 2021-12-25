#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <stdio.h>

class Graphics
{
public:
    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;

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
    SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text);

    void ClearBackBuffer();

    void DrawTexture(SDL_Texture* tex, SDL_Rect* clip = NULL, SDL_Rect* rend = NULL);

    void Render();

private:
    Graphics();
    ~Graphics();

    bool Init();
};
