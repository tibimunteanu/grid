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

    bool mClipped;
    SDL_Rect mRenderRect;
    SDL_Rect mClipRect;

public:
    Texture(std::string filename);
    Texture(std::string filename, int x, int y, int w, int h);
    ~Texture();

    virtual void Render();
};
