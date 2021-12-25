#pragma once

#include "Assets.h"

class Audio
{
private:
    static Audio* sInstance;

    Assets* mAssets;

public:
    static Audio* Instance();
    static void Release();

    void PlayMusic(const std::string& filename, int loops = -1);
    void PauseMusic();
    void ResumeMusic();

    void PlaySfx(const std::string& filename, int loops = -1, int channel = 0);

private:
    Audio();
    ~Audio();
};
