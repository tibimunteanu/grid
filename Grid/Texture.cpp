#include "Texture.h"

// public API
Texture::Texture(std::string filename)
{
    mTex = Assets::Instance()->GetTexture(filename);

    SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

    mClipped = false;

    mRenderRect.w = mWidth;
    mRenderRect.h = mHeight;
}

Texture::Texture(std::string filename, int x, int y, int w, int h)
{
    mTex = Assets::Instance()->GetTexture(filename);

    mClipped = true;

    mWidth = w;
    mHeight = h;

    mRenderRect.w = w;
    mRenderRect.h = h;

    mClipRect.x = x;
    mClipRect.y = y;
    mClipRect.w = w;
    mClipRect.h = h;
}

Texture::Texture(std::string text, std::string fontpath, int size, SDL_Color color)
{
    mTex = Assets::Instance()->GetText(text, fontpath, size, color);

    SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

    mClipped = false;

    mRenderRect.w = mWidth;
    mRenderRect.h = mHeight;
}

Texture::~Texture()
{
    mTex = NULL;
}


void Texture::Render()
{
    Vector2 pos = Pos(world);
    Vector2 scale = Scale(world);
    float rot = Rotation(world);

    mRenderRect.x = (int)(pos.x - mWidth * scale.x * 0.5f);
    mRenderRect.y = (int)(pos.y - mHeight * scale.y * 0.5f);
    mRenderRect.w = (int)(mWidth * scale.x);
    mRenderRect.h = (int)(mHeight * scale.y);

    Graphics::Instance()->DrawTexture(mTex, mClipped ? &mClipRect : NULL, &mRenderRect, rot);
}