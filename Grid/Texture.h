#pragma once

#include "Entity.h"
#include "Assets.h"

class Texture : public Entity
{
private:
    SDL_Texture* mTex;

    Graphics* mGraphics;

    int mWidth;
    int mHeight;

public:
    Texture(std::string filename);
    ~Texture();

    virtual void Render();
};
