#include "Graphics.h"

Graphics* Graphics::sInstance = NULL;
bool Graphics::sInitialized = false;


Graphics* Graphics::Instance()
{
    if (sInstance == NULL)
    {
        sInstance = new Graphics();
    }
    return sInstance;
}


bool Graphics::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL Initialization Error: %s\n", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow("Grid",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (mWindow == NULL)
    {
        printf("Window Creation Error: %s\n", SDL_GetError());
        return false;
    }

    // init renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

    if (mRenderer == NULL)
    {
        printf("Renderer Creation Error: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // init image library
    int flags = IMG_INIT_PNG;
    if (!(IMG_Init(flags) & flags))
    {
        printf("IMG Initialization Error: %s\n", IMG_GetError());
        return false;
    }

    // init ttf
    if (TTF_Init() == -1)
    {
        printf("TTF Initialization Error: %s\n", TTF_GetError());
        return false;
    }

    mBackBuffer = SDL_GetWindowSurface(mWindow);

    return true;
}

void Graphics::Release()
{
    delete sInstance;
    sInstance = NULL;

    sInitialized = false;
}

bool Graphics::Initialized()
{
    return sInitialized;
}


Graphics::Graphics()
{
    mBackBuffer = NULL;

    sInitialized = Init();
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(mWindow);
    mWindow = NULL;

    SDL_DestroyRenderer(mRenderer);
    mRenderer = NULL;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}



SDL_Texture* Graphics::LoadTexture(std::string path)
{
    SDL_Surface* surface = IMG_Load(path.c_str());

    if (surface == NULL)
    {
        printf("IMG Load Error: Path(%s) - Error(%s)\n", path.c_str(), IMG_GetError());
        return NULL;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);

    if (tex == NULL)
    {
        printf("Create Texture Error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_FreeSurface(surface);

    return tex;
}

SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), { 0, 0, 0 });

    if (surface == NULL)
    {
        printf("Text Render Error: %s\n", TTF_GetError());
        return NULL;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);

    if (tex == NULL)
    {
        printf("Text Texture Createion Error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_FreeSurface(surface);

    return tex;
}


void Graphics::ClearBackBuffer()
{
    SDL_RenderClear(mRenderer);
}

void Graphics::DrawTexture(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend)
{
    SDL_RenderCopy(mRenderer, tex, clip, rend);
}

void Graphics::Render()
{
    SDL_RenderPresent(mRenderer);
}
