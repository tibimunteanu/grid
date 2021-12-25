#pragma once

#include <string>
#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Graphics
{
public:
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const char* TITLE = "Grid";


private:
    static Graphics* sInstance;
    static bool sInitialized;

public:
    static Graphics* Instance();
    static void Release();


private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;

private:
    Graphics();
    ~Graphics();

public:
    SDL_Texture* LoadTexture(std::string path);
    SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);

    void ClearBackBuffer();

    void DrawTexture(SDL_Texture* tex, SDL_Rect* clip = NULL, SDL_Rect* rend = NULL,
                     float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void Render();
};
