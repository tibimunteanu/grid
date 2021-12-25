#include "Audio.h"

// static
Audio* Audio::sInstance = NULL;
bool Audio::sInitialized = false;

Audio* Audio::Instance()
{
    if (sInstance == NULL)
    {
        sInstance = new Audio();
        if (!sInitialized)
        {
            Release();
        }
    }
    return sInstance;
}

void Audio::Release()
{
    if (sInstance)
    {
        delete sInstance;
        sInstance = NULL;
    }

    sInitialized = false;
}


// private
Audio::Audio()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
    {
        printf("Mixer Initialization Error: %s\n", Mix_GetError());
        return;
    }

    sInitialized = true;
}

Audio::~Audio()
{
    Mix_Quit();
}


// public API
void Audio::PlayMusic(const std::string& filename, int loops)
{
    Mix_PlayMusic(Assets::Instance()->GetMusic(filename), loops);
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
    Mix_PlayChannel(channel, Assets::Instance()->GetSfx(filename), loops);
}
