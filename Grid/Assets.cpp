#include "Assets.h"

Assets* Assets::sInstance = NULL;

Assets* Assets::Instance()
{
    if (sInstance == NULL)
    {
        sInstance = new Assets();
    }
    return sInstance;
}

void Assets::Release()
{
    delete sInstance;
    sInstance = NULL;
}

Assets::Assets()
{
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
}

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