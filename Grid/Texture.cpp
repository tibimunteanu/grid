#include "Texture.h"

Texture::Texture(std::string filename)
{
    mGraphics = Graphics::Instance();

    mTex = Assets::Instance()->GetTexture(filename);

    SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

    mClipped = false;

    mRenderRect.w = mWidth;
    mRenderRect.h = mHeight;
}

Texture::Texture(std::string filename, int x, int y, int w, int h)
{
    mGraphics = Graphics::Instance();

    mTex = Assets::Instance()->GetTexture(filename);

    mClipped = true;

    mWidth = w;
    mHeight = h;

    mRenderRect.w = w;
    mRenderRect.h = h;

    mClipRect.x = x;
    mClipRect.y = y;
    mClipRect.w = mWidth;
    mClipRect.h = mHeight;
}

Texture::Texture(std::string text, std::string fontpath, int size, SDL_Color color)
{
    mGraphics = Graphics::Instance();

    mTex = Assets::Instance()->GetText(text, fontpath, size, color);

    SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

    mClipped = false;

    mRenderRect.w = mWidth;
    mRenderRect.h = mHeight;
}

Texture::~Texture()
{
    mTex = NULL;
    mGraphics = NULL;
}


void Texture::Render()
{
    Vector2 pos = Pos(world);
    mRenderRect.x = (int)(pos.x - mWidth * 0.5f);
    mRenderRect.y = (int)(pos.y - mHeight * 0.5f);

    mGraphics->DrawTexture(mTex, mClipped ? &mClipRect : NULL, &mRenderRect);
}