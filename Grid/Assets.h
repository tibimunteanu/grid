#pragma once

#include "Graphics.h"
#include <SDL_mixer.h>
#include <map>

class Assets
{
private:
    static Assets* sInstance;

    std::map<std::string, SDL_Texture*> mTextures;
    std::map<std::string, SDL_Texture*> mText;
    std::map<std::string, TTF_Font*> mFonts;
    std::map<std::string, Mix_Music*> mMusic;
    std::map<std::string, Mix_Chunk*> mSfx;

public:
    static Assets* Instance();
    static void Release();

    SDL_Texture* GetTexture(const std::string& filename);
    SDL_Texture* GetText(const std::string& text, const std::string& filename, int size, SDL_Color color);

    Mix_Music* GetMusic(const std::string& filename);
    Mix_Chunk* GetSfx(const std::string& filename);

private:
    Assets();
    ~Assets();

    TTF_Font* GetFont(const std::string& filename, int size);
};
