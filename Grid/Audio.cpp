#include "Audio.h"

Audio* Audio::sInstance = NULL;

Audio* Audio::Instance()
{
    if (sInstance == NULL)
    {
        sInstance = new Audio();
    }
    return sInstance;
}

void Audio::Release()
{
    delete sInstance;
    sInstance = NULL;
}

Audio::Audio()
{
    mAssets = Assets::Instance();

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
    {
        printf("Mixer Initialization Error: %s\n", Mix_GetError());
    }
}

Audio::~Audio()
{
    mAssets = NULL;
    Mix_Quit();
}

void Audio::PlayMusic(const std::string& filename, int loops)
{
    Mix_PlayMusic(mAssets->GetMusic(filename), loops);
}

void Audio::PauseMusic()
{
    if (Mix_PlayingMusic() != 0)
    {
        Mix_PauseMusic();
    }
}

void Audio::ResumeMusic()
{
    if (Mix_PausedMusic() != 0)
    {
        Mix_ResumeMusic();
    }
}

void Audio::PlaySfx(const std::string& filename, int loops, int channel)
{
    Mix_PlayChannel(channel, mAssets->GetSfx(filename), loops);
}
