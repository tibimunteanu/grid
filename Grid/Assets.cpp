#include "Assets.h"

// static
Assets* Assets::sInstance = NULL;
bool Assets::sInitialized = false;

Assets* Assets::Instance()
{
    if (sInstance == NULL)
    {
        sInstance = new Assets();
        if (!sInitialized)
        {
            Release();
        }
    }
    return sInstance;
}

void Assets::Release()
{
    if (sInstance)
    {
        delete sInstance;
        sInstance = NULL;
    }

    sInitialized = false;
}


// private
Assets::Assets()
{
    sInitialized = true;
}

Assets::~Assets()
{
    for (auto tex : mTextures)
    {
        if (tex.second != NULL)
        {
            SDL_DestroyTexture(tex.second);
        }
    }
    mTextures.clear();

    for (auto text : mText)
    {
        if (text.second != NULL)
        {
            SDL_DestroyTexture(text.second);
        }
    }
    mText.clear();

    for (auto font : mFonts)
    {
        if (font.second != NULL)
        {
            TTF_CloseFont(font.second);
        }
    }
    mFonts.clear();

    for (auto music : mMusic)
    {
        if (music.second != NULL)
        {
            Mix_FreeMusic(music.second);
        }
    }
    mMusic.clear();

    for (auto sfx : mSfx)
    {
        if (sfx.second != NULL)
        {
            Mix_FreeChunk(sfx.second);
        }
    }
    mSfx.clear();
}


TTF_Font* Assets::GetFont(const std::string& filename, int size)
{
    std::string fullPath = SDL_GetBasePath();
    fullPath.append("Assets/" + filename);
    std::string key = fullPath + (char)size;

    if (mFonts[key] == nullptr)
    {
        mFonts[key] = TTF_OpenFont(fullPath.c_str(), size);
        if (mFonts[key] == nullptr)
        {
            printf("Font Loading Error: Font-%s Error-%s", filename.c_str(), TTF_GetError());
            return nullptr;
        }
    }

    return mFonts[key];
}


// public API
SDL_Texture* Assets::GetTexture(const std::string& filename)
{
    std::string fullPath = SDL_GetBasePath();
    fullPath.append("Assets/" + filename);

    if (mTextures[fullPath] == nullptr)
    {
        mTextures[fullPath] = Graphics::Instance()->LoadTexture(fullPath);
    }

    return mTextures[fullPath];
}

SDL_Texture* Assets::GetText(const std::string& text, const std::string& filename, int size, SDL_Color color)
{
    std::string key = text + filename + (char)size + (char)color.r + (char)color.g + (char)color.b;

    if (mText[key] == nullptr)
    {
        TTF_Font* font = GetFont(filename, size);

        mText[key] = Graphics::Instance()->CreateTextTexture(font, text, color);
    }

    return mText[key];
}


Mix_Music* Assets::GetMusic(const std::string& filename)
{
    std::string fullPath = SDL_GetBasePath();
    fullPath.append("Assets/" + filename);

    if (mMusic[fullPath] == nullptr)
    {
        mMusic[fullPath] = Mix_LoadMUS(fullPath.c_str());
        if (mMusic[fullPath] == nullptr)
        {
            printf("Music Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
            return nullptr;
        }
    }

    return mMusic[fullPath];
}

Mix_Chunk* Assets::GetSfx(const std::string& filename)
{
    std::string fullPath = SDL_GetBasePath();
    fullPath.append("Assets/" + filename);

    if (mSfx[fullPath] == nullptr)
    {
        mSfx[fullPath] = Mix_LoadWAV(fullPath.c_str());
        if (mSfx[fullPath] == nullptr)
        {
            printf("Sfx Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
            return nullptr;
        }
    }

    return mSfx[fullPath];
}
