#pragma once

#include "Graphics.h"
#include <map>

class Assets
{
private:
    static Assets* sInstance;

    std::map<std::string, SDL_Texture*> mTextures;

public:
    static Assets* Instance();
    static void Release();

    SDL_Texture* GetTexture(const std::string& filename);

private:
    Assets();
    ~Assets();
};
